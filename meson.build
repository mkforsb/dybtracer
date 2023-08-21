project('dybtracer', ['cpp', 'c'], version: '1.0.0', license: 'MIT')

sources = files('src/camera.cpp',
                'src/gtkfiledialog.cpp',
                'src/light.cpp',
                'src/main.cpp',
                'src/material.cpp',
                'src/mesh.cpp',
                'src/objreader.cpp',
                'src/raytracingrenderer.cpp',
                'src/scene.cpp',
                'src/sdlgui.cpp',
                'src/sdltexture.cpp',
                'src/sphere.cpp',
                'src/stlreader.cpp',
                'src/tribox3.c',
                'src/wireframeelement.cpp',
                'src/wireframerenderer.cpp')

dependencies = [dependency('glm'),
                dependency('gtk+-3.0'),
                dependency('lua-5.3-c++'),
                dependency('sdl2'),
                dependency('SDL2_image')]

executable('dybtracer', sources, dependencies: dependencies)
