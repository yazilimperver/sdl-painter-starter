# SDLPainter starter

A template for a new project that draws with
[SDLPainter](https://github.com/yazilimperver/sdl-painter), a C++17 2D drawing
library for SDL3 with OpenGL 3.3 and Vulkan 1.1 backends.

Click **Use this template** on GitHub, clone your new repository and build it.
You get a window with a rotating card and a dot that follows the mouse; press
<kbd>Esc</kbd> to quit.

| File | What it is |
|---|---|
| `src/main.cpp` | The application: an `sdl_painter::Application` subclass |
| `CMakeLists.txt` | `find_package(sdl_painter)`, warnings, DLL copy on Windows |
| `conanfile.txt` | Requires `sdl_painter/1.4.0` |
| `.github/workflows/build.yml` | Builds on Linux and Windows |

## Requirements

- CMake 3.21 or newer
- A C++17 compiler: MSVC 2019 or newer, GCC 8+ or Clang 7+
- [Conan 2](https://docs.conan.io/2/installation.html)
- Linux or Windows (macOS is not supported by SDLPainter yet)

## 1. Get the sdl_painter package

SDLPainter is
[under review on Conan Center](https://github.com/conan-io/conan-center-index/pull/31238).
Until it is merged, create the package in your local Conan cache once, from the
recipe that was submitted there:

```bash
git clone https://github.com/yazilimperver/sdl-painter.git
cd sdl-painter
git checkout bf20fc28ae8dc6cb7e226cd8f313cd5e5c187f6c
conan create packaging/conan-center/all --version=1.4.0 --build=missing -s compiler.cppstd=17
```

After the merge this step goes away; `conan install` below fetches the package.

## 2. Build

```bash
conan install . --build=missing -s compiler.cppstd=17
```

Windows:

```bash
cmake --preset conan-default
cmake --build --preset conan-release
build\Release\starter.exe
```

Linux:

```bash
cmake --preset conan-release
cmake --build --preset conan-release
./build/Release/starter
```

`-s compiler.cppstd=17` is needed when your Conan profile uses an older
standard; the profile Conan detects for MSVC defaults to C++14.

On **Linux**, SDL needs X11 and Wayland development packages. Conan can install
them with your system package manager: add
`-c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True`
to both Conan commands.

## Options

- **Vulkan backend:** add `-o "sdl_painter/*:with_vulkan=True"` to the Conan
  commands and set `config.backend = sdl_painter::RendererBackend::kVulkan` in
  `main.cpp`.
- **Shared library:** add `-o "sdl_painter/*:shared=True"`. On Windows the
  build copies the DLLs next to the executable.
- **vcpkg instead of Conan:** see the vcpkg section of the
  [SDLPainter README](https://github.com/yazilimperver/sdl-painter#vcpkg).

## Next steps

- [Examples](https://github.com/yazilimperver/sdl-painter/tree/main/examples):
  shapes, transforms, text, images, render targets, input and small games
- [Getting started](https://github.com/yazilimperver/sdl-painter/blob/main/doc/en/getting-started.md)
  and the rest of the [documentation](https://github.com/yazilimperver/sdl-painter/tree/main/doc/en)

## License

The template is released under [MIT No Attribution](LICENSE): use it for
anything, no notice needed. SDLPainter itself is MIT licensed.
