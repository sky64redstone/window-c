cmake_minimum_required(VERSION 3.16)
project(window_c C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    window
    GIT_REPOSITORY https://github.com/sky64redstone/window.git
    GIT_TAG main
)
FetchContent_MakeAvailable(window)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${window_SOURCE_DIR}/include
)

add_library(window_c STATIC src/window_c.cpp)

target_link_libraries(window_c PRIVATE window)

# Compile the test executable
project(window_c_test C)

add_executable(window_c_test test/main.c)

target_include_directories(window_c_test PRIVATE include)

target_link_libraries(window_c_test PRIVATE window_c GL)
