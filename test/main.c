#include <stdio.h>
#include <GL/gl.h>
#include "window_c.h"

int main(void) {
  window_handle* window = window_create_handle();

  window_set_appname(window, "mywindowapp");
  window_set_glversion(window, 3, 3);

  window_result result = window_create(window, 800, 600, "Test Window");
  if (result != WINDOW_RESULT_SUCCESS) {
    fprintf(stderr, "Failed to create window\n");
    return 1;
  }

  result = window_make_opengl_context(window);
  if (result != WINDOW_RESULT_SUCCESS) {
    fprintf(stderr, "Failed to create opengl context\n");
    return 1;
  }

  glViewport(0, 0, 300, 200);
  glClearColor(0.f, 0.f, 0.f, 1.f);

  while (window_is_open(window)) {
    window_poll_events(window);
    glClear(GL_COLOR_BUFFER_BIT);
    window_swap_buffers(window);
  }

  window_destroy(window);

  return 0;
}

