#include "window_c.h"
#include "window.hpp"

#include <new>

struct callback_state {
  window_key_event_fn key_fn = nullptr;
  window_button_event_fn button_fn = nullptr;
  window_dblclk_event_fn dblclk_fn = nullptr;
  window_mouse_event_fn mouse_fn = nullptr;
  window_scroll_event_fn vscroll_fn = nullptr;
  window_scroll_event_fn hscroll_fn = nullptr;
  window_size_event_fn size_fn = nullptr;

  void* user_data;
};

struct window_handle {
  window::window* impl = nullptr;
  callback_state callbacks{};
};

namespace {

  static window_result convert(window::result r) {
    return static_cast<window_result>(r);
  }

  static window_backend convert(window::backend b) {
    return static_cast<window_backend>(b);
  }

  static window_key_descriptor convert(window::key_descriptor k) {
    return window_key_descriptor{
      static_cast<window_key>(k.k),
      k.description
    };
  }

  static window_button_descriptor convert(window::button_descriptor b) {
    return window_button_descriptor{
      static_cast<window_button>(b.b),
      b.description
    };
  }

  static window_handle* from_data(void* data) {
    return static_cast<window_handle*>(data);
  }

  static void key_trampoline(bool down, window::key_descriptor& key, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.key_fn) return;
    h->callbacks.key_fn(h->callbacks.user_data, down, convert(key));
  }

  static void button_trampoline(bool down, window::button_descriptor& button, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.button_fn) return;
    h->callbacks.button_fn(h->callbacks.user_data, down, convert(button));
  }

  static void dblclk_trampoline(window::button_descriptor& button, void* data) {
    auto* h = from_data(data);
    if (!h) return;

    if (!h->callbacks.dblclk_fn) {
      button_trampoline(true, button, data);
      return;
    }

    h->callbacks.dblclk_fn(h->callbacks.user_data, convert(button));
  }

  static void mouse_trampoline(int x, int y, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.mouse_fn) return;
    h->callbacks.mouse_fn(h->callbacks.user_data, x, y);
  }

  static void vscroll_trampoline(float delta, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.vscroll_fn) return;
    h->callbacks.vscroll_fn(h->callbacks.user_data, delta);
  }

  static void hscroll_trampoline(float delta, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.hscroll_fn) return;
    h->callbacks.hscroll_fn(h->callbacks.user_data, delta);
  }

  static void size_trampoline(int w, int hgt, void* data) {
    auto* h = from_data(data);
    if (!h || !h->callbacks.size_fn) return;
    h->callbacks.size_fn(h->callbacks.user_data, w, hgt);
  }

  static void bind_callbacks(window_handle* handle) {
    handle->impl->input.key_event = &key_trampoline;
    handle->impl->input.button_event = &button_trampoline;
    handle->impl->input.dblclk_event = &dblclk_trampoline;
    handle->impl->input.mouse_event = &mouse_trampoline;
    handle->impl->input.vscroll_event = &vscroll_trampoline;
    handle->impl->input.hscroll_event = &hscroll_trampoline;
    handle->impl->input.size_event = &size_trampoline;
  }

} // namespace

extern "C" {

  window_handle* window_create_handle(void) {
    auto* handle = new (std::nothrow) window_handle();
    if (!handle) return nullptr;

    handle->impl = new (std::nothrow) window::window();
    if (!handle->impl) {
      delete handle;
      return nullptr;
    }

    handle->impl->set_user_data(handle);
    bind_callbacks(handle);

    return handle;
  }

  void window_destroy(window_handle* handle) {
    if (!handle) return;

    if (handle->impl) {
      handle->impl->destroy();
      delete handle->impl;
      handle->impl = nullptr;
    }

    delete handle;
  }

  window_result window_create(window_handle* handle, int width, int height, const char* title) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->create(width, height, title));
  }

  window_result window_set_title(window_handle* handle, const char* title) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->set_title(title));
  }

  window_result window_set_size(window_handle* handle, int width, int height) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->set_size(width, height));
  }

  bool window_is_open(const window_handle* handle) {
    return handle && handle->impl && handle->impl->is_open();
  }

  window_result window_poll_events(window_handle* handle) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->poll_events());
  }

  window_result window_make_opengl_context(window_handle* handle) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->make_opengl_context());
  }

  window_result window_swap_buffers(const window_handle* handle) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->swap_buffers());
  }

  window_result window_swap_interval(const window_handle* handle, int interval) {
    if (!handle || !handle->impl) return WINDOW_RESULT_BADWINDOW;
    return convert(handle->impl->swap_interval(interval));
  }

  window_backend window_get_backend(const window_handle* handle) {
    if (!handle || !handle->impl) return WINDOW_BACKEND_WIN32;
    return convert(handle->impl->get_backend());
  }

  void* window_set_user_data(window_handle* handle, void* data) {
    if (!handle || !handle->impl) return NULL;
    return handle->impl->set_user_data(data);
  }

  void window_set_key_event(window_handle* handle, window_key_event_fn callback) {
    if (!handle) return;
    handle->callbacks.key_fn = callback;
  }

  void window_set_button_event(window_handle* handle, window_button_event_fn callback) {
    if (!handle) return;
    handle->callbacks.button_fn = callback;
  }

  void window_set_dblclk_event(window_handle* handle, window_dblclk_event_fn callback) {
    if (!handle) return;
    handle->callbacks.dblclk_fn = callback;
  }

  void window_set_mouse_event(window_handle* handle, window_mouse_event_fn callback) {
    if (!handle) return;
    handle->callbacks.mouse_fn = callback;
  }

  void window_set_vscroll_event(window_handle* handle, window_scroll_event_fn callback) {
    if (!handle) return;
    handle->callbacks.vscroll_fn = callback;
  }

  void window_set_hscroll_event(window_handle* handle, window_scroll_event_fn callback) {
    if (!handle) return;
    handle->callbacks.hscroll_fn = callback;
  }

  void window_set_size_event(window_handle* handle, window_size_event_fn callback) {
    if (!handle) return;
    handle->callbacks.size_fn = callback;
  }

} // extern "C"
