# libwindow

`window-c` is a lightweight c port of the [libwindow](https://github.com/sky64redstone/window) library for creating and managing **cross-platform windows**.

---

## Usage

A minimal usage example can be found in:

```
test/main.c
```

After building the project, the example program will be compiled automatically.

Run it with:

```bash
cd build
./window_c_test
```

For API details, refer to the headers:

```
include/window_c.h
include/window_input_c.h
```

---

## Supported Platforms

Currently supported platforms:

* Linux (both X11 and Wayland)
* Windows

---

## Requirements

To build **window-c**, you need a C++ compiler, CMake, and a build tool.
On Linux you will also need development libraries depending on whether you use **X11** or **Wayland**.
Alternatively, you could install the necessary libraries for both window servers, and this library would automatically select the appropriate server at runtime.

* A C/C++ compiler (e.g. GCC or Clang)
* CMake
* Git

> [!WARNING]
> The external links and package names below are provided for convenience only, and I do not guarantee their validity, safety, or that they are free of malware, so you should verify downloads and sources yourself before installing any software.

### Windows

Recommended setup:

1. Install **Visual Studio** with the **Desktop development with C++** workload
   [https://visualstudio.microsoft.com/](https://visualstudio.microsoft.com/)

2. Install **CMake**
   [https://cmake.org/download/](https://cmake.org/download/)

3. Install **Git**
   [https://git-scm.com/downloads](https://git-scm.com/downloads)

After installation you can build the project from a **Developer Command Prompt** or **PowerShell**.

### Linux (Ubuntu / Debian)

Install the basic build tools:

```bash
sudo apt install build-essential cmake git
```

#### X11 Support

```bash
sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```

#### Wayland Support

```bash
sudo apt install libwayland-dev wayland-protocols libxkbcommon-dev
```

You only need the packages for the window system you intend to support.

---

### Linux (Arch / Manjaro)

Install the basic build tools:

```bash
sudo pacman -S base-devel cmake git
```

#### X11 Support

```bash
sudo pacman -S libx11 libxrandr libxinerama libxcursor libxi
```

#### Wayland Support

```bash
sudo pacman -S wayland wayland-protocols libxkbcommon
```

You only need the packages for the window system you intend to support.

---

## Installation

Make sure you have installed make, cmake and a compiler that is supported by cmake

Clone the repository:

```bash
git clone https://github.com/sky64redstone/window-c.git
cd window-c
```

Build the library with the following commands
> Windows users: after running `cmake ..` you can open the project in Visual Studio, since CMake doesn't create Makefiles on Windows

```bash
mkdir build
cd build
cmake ..
make
```

---

## See also
[libwindow/README.md](https://github.com/sky64redstone/window/blob/main/README.md)
