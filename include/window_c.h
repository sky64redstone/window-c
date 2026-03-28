#ifndef WINDOW_C_H
  #define WINDOW_C_H

  #include "window_input_c.h"

  #ifdef __cplusplus
  extern "C" {
  #endif

    typedef struct window_handle window_handle;

    typedef enum window_result {
      WINDOW_RESULT_SUCCESS = 0,
      WINDOW_RESULT_ALREADYEXISTS,
      WINDOW_RESULT_UNSUPPORTED,
      WINDOW_RESULT_CONNECTIONFAILED,
      WINDOW_RESULT_CREATIONFAILED,
      WINDOW_RESULT_BADWINDOW,
      WINDOW_RESULT_BADALLOC,
      WINDOW_RESULT_UNKNOWNFAILURE,
      WINDOW_RESULT_QUIT
    } window_result;

    typedef enum window_backend {
      WINDOW_BACKEND_WIN32 = 0,
      WINDOW_BACKEND_X11,
      WINDOW_BACKEND_WAYLAND
    } window_backend;

    struct window_handle;
    typedef struct window_handle window_handle;

    window_handle* window_create_handle(void);
    void window_destroy(window_handle* handle);
    window_result window_create(window_handle* handle, int width, int height, const char* title);
    window_result window_set_title(window_handle* handle, const char* title);
    window_result window_set_size(window_handle* handle, int width, int height);
    bool window_is_open(const window_handle* handle);
    window_result window_poll_events(window_handle* handle);
    window_result window_make_opengl_context(window_handle* handle);
    window_result window_swap_buffers(const window_handle* handle);
    window_result window_swap_interval(const window_handle* handle, int interval);
    window_backend window_get_backend(const window_handle* handle);

    void window_set_key_event(window_handle* handle, window_key_event_fn callback, void* user_data);
    void window_set_button_event(window_handle* handle, window_button_event_fn callback, void* user_data);
    void window_set_dblclk_event(window_handle* handle, window_dblclk_event_fn callback, void* user_data);
    void window_set_mouse_event(window_handle* handle, window_mouse_event_fn callback, void* user_data);
    void window_set_vscroll_event(window_handle* handle, window_scroll_event_fn callback, void* user_data);
    void window_set_hscroll_event(window_handle* handle, window_scroll_event_fn callback, void* user_data);
    void window_set_size_event(window_handle* handle, window_size_event_fn callback, void* user_data);

  #ifdef __cplusplus
  }
  #endif

#endif
