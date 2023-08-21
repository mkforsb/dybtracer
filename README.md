# DYBTracer

![Screenshot](https://raw.githubusercontent.com/mkforsb/dybtracer/main/doc/screenshot.png)

DYBTracer is a simple raytracer with Lua scripting support. DYBTracer can draw spheres and triangles with or without textures using Phong lighting/shading.

## Building

DYBTracer is built using Meson. It is highly recommended to use the `release` buildtype for optimization/performance.

    meson setup --buildtype release build
    ninja -C build

## Running

    ./build/dybtracer scripts/dybtracer.lua

## Controls
| Key(s)     | Function                                                |
|------------|---------------------------------------------------------|
| Esc        | Quit                                                    |
| WASD       | Move camera                                             |
| 2          | Raise camera                                            |
| X          | Lower camera                                            |
| Arrow keys | Rotate and pitch camera                                 |
| F          | Load script with file dialog                            |
| R          | Switch renderer (toggle between wireframe and raytrace) |
| T          | In wireframe mode: raytrace single frame                |
| Q          | Remove all objects from current scene                   |
| Y,I        | Move movable light forwards, back                       |
| H,J        | Move movable light left, right                          |
| U,N        | Move movable light up, down                             |
| F5         | Reload Lua script                                       |
| F9         | Toggle display of normals in wireframe renderer         |
| F10        | Toggle between different number of shadow samples       |
| F11        | Print camera position                                   |
