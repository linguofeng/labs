luajit binding C & C++
===

## install luajit

```bash
$ brew install luajit
```

## build binding C Test

```bash
$ luajit tools/generate_ffi.lua header
$ gcc \
    -lluajit-5.1 \
    -I./include \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o mainc \
    src/main.c
```

## build binding C++ Test

```bash
$ g++ \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o maincpp \
    main.cpp
```

```bash
$ luajit tools/generate_ffi.lua bindings
$ luajit tools/generate_dylib.lua student bindings
$ g++ \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -l luajit-5.1 \
    -I include
    -I /usr/local/include/luajit-2.0 \
    -o maincpp2 \
    src/main2.cpp
```
