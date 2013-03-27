luajit binding C & C++
===

## install luajit

```bash
$ brew install luajit
```

## build binding C Test

```bash
$ gcc-4.7 \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o mainc \
    main.c
```

## build binding C++ Test

```bash
$ luajit generate_ffi.lua
$ g++-4.7 \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o maincpp \
    main.cpp Student.cpp bindings.cpp
```
