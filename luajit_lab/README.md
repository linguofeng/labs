luajit_lab
===

# luajit binding C & C++

## install luajit

```shell
$ brew install luajit
```

## build binding C Test

```shell
$ gcc-4.7 \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    main.c
```

## build binding C++ Test

```shell
$ luajit generate_ffi.lua
$ g++-4.7 \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    main.cpp Student.cpp bindings.cpp
```shell
