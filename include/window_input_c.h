#ifndef WINDOW_INPUT_C_H
  #define WINDOW_INPUT_C_H

  #ifdef __cplusplus
  extern "C" {
  #endif

    typedef enum window_key {
      WINDOW_KEY_NONE = 0,
      WINDOW_KEY_A, WINDOW_KEY_B, WINDOW_KEY_C, WINDOW_KEY_D, WINDOW_KEY_E, WINDOW_KEY_F, WINDOW_KEY_G,
      WINDOW_KEY_H, WINDOW_KEY_I, WINDOW_KEY_J, WINDOW_KEY_K, WINDOW_KEY_L, WINDOW_KEY_M, WINDOW_KEY_N,
      WINDOW_KEY_O, WINDOW_KEY_P, WINDOW_KEY_Q, WINDOW_KEY_R, WINDOW_KEY_S, WINDOW_KEY_T, WINDOW_KEY_U,
      WINDOW_KEY_V, WINDOW_KEY_W, WINDOW_KEY_X, WINDOW_KEY_Y, WINDOW_KEY_Z,
      WINDOW_KEY_0, WINDOW_KEY_1, WINDOW_KEY_2, WINDOW_KEY_3, WINDOW_KEY_4,
      WINDOW_KEY_5, WINDOW_KEY_6, WINDOW_KEY_7, WINDOW_KEY_8, WINDOW_KEY_9,
      WINDOW_KEY_NP1, WINDOW_KEY_NP2, WINDOW_KEY_NP3, WINDOW_KEY_NP4, WINDOW_KEY_NP5,
      WINDOW_KEY_NP6, WINDOW_KEY_NP7, WINDOW_KEY_NP8, WINDOW_KEY_NP9, WINDOW_KEY_NP0,
      WINDOW_KEY_SHIFT,
      WINDOW_KEY_CTRL,
      WINDOW_KEY_ALT,
      WINDOW_KEY_SUPER,
      WINDOW_KEY_CAPSLOCK,
      WINDOW_KEY_BACKSPACE,
      WINDOW_KEY_TAB,
      WINDOW_KEY_RETURN,
      WINDOW_KEY_SPACE,
      WINDOW_KEY_ESCAPE,
      WINDOW_KEY_NP_MUL,
      WINDOW_KEY_NP_ADD,
      WINDOW_KEY_NP_SUB,
      WINDOW_KEY_NP_DEC,
      WINDOW_KEY_NP_SEP,
      WINDOW_KEY_NP_DIV,
      WINDOW_KEY_LEFT,
      WINDOW_KEY_RIGHT,
      WINDOW_KEY_UP,
      WINDOW_KEY_DOWN,
      WINDOW_KEY_F1, WINDOW_KEY_F2, WINDOW_KEY_F3, WINDOW_KEY_F4, WINDOW_KEY_F5,
      WINDOW_KEY_F6, WINDOW_KEY_F7, WINDOW_KEY_F8, WINDOW_KEY_F9, WINDOW_KEY_F10,
      WINDOW_KEY_F11, WINDOW_KEY_F12, WINDOW_KEY_F13, WINDOW_KEY_F14, WINDOW_KEY_F15,
      WINDOW_KEY_F16, WINDOW_KEY_F17, WINDOW_KEY_F18, WINDOW_KEY_F19, WINDOW_KEY_F20,
      WINDOW_KEY_F21, WINDOW_KEY_F22, WINDOW_KEY_F23, WINDOW_KEY_F24,
      WINDOW_KEY_INSERT,
      WINDOW_KEY_DELETE,
      WINDOW_KEY_HOME,
      WINDOW_KEY_END,
      WINDOW_KEY_PAGE_UP,
      WINDOW_KEY_PAGE_DOWN,
      WINDOW_KEY_NUMLOCK,
      WINDOW_KEY_PRINT,
      WINDOW_KEY_SCROLLLOCK,
      WINDOW_KEY_PAUSE,
      WINDOW_KEY_PLUS,
      WINDOW_KEY_COMMA,
      WINDOW_KEY_MINUS,
      WINDOW_KEY_PERIOD,
      WINDOW_KEY_OEM1,
      WINDOW_KEY_OEM2,
      WINDOW_KEY_OEM3,
      WINDOW_KEY_OEM4,
      WINDOW_KEY_OEM5,
      WINDOW_KEY_OEM6,
      WINDOW_KEY_OEM7,
      WINDOW_KEY_OEM8,
      WINDOW_KEY_OEM9,
      WINDOW_KEY_COUNT
    } window_key;

    typedef enum window_button {
      WINDOW_BUTTON_NONE = 0,
      WINDOW_BUTTON_LEFT,
      WINDOW_BUTTON_RIGHT,
      WINDOW_BUTTON_MIDDLE,
      WINDOW_BUTTON_X1,
      WINDOW_BUTTON_X2,
      WINDOW_BUTTON_COUNT
    } window_button;

    typedef struct window_key_descriptor {
      window_key key;
      const char* description;
    } window_key_descriptor;

    typedef struct window_button_descriptor {
      window_button button;
      const char* description;
    } window_button_descriptor;

    typedef void (*window_key_event_fn)(void* user_data, bool down, window_key_descriptor key);
    typedef void (*window_button_event_fn)(void* user_data, bool down, window_button_descriptor button);
    typedef void (*window_dblclk_event_fn)(void* user_data, window_button_descriptor button);
    typedef void (*window_mouse_event_fn)(void* user_data, int x, int y);
    typedef void (*window_scroll_event_fn)(void* user_data, float delta);
    typedef void (*window_size_event_fn)(void* user_data, int width, int height);

  #ifdef __cplusplus
  }
  #endif

#endif
