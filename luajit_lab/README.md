luajit binding C & C++
===

## luajit install

```bash
$ brew install luajit cmake
```

## generate ffi and so

```bash
$ ./build.sh
```
## build

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```


old---------------------

## luajit binding C Test

```bash
$ luajit tools/generate_ffi.lua header
$ gcc \
    -l luajit-5.1 \
    -I include \
    -I /usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o mainc \
    src/main.c
$ ./mainc
```

## luajit C++ Test

```bash
$ g++ \
    -l luajit-5.1 \
    -I /usr/local/include/luajit-2.0 \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o maincpp \
    src/main.cpp
$ ./maincpp
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
$ ./maincpp2
```

# luajit Callback

## luajit callback Test

```bash
$ gcc \
    -lluajit-5.1 \
    -I/usr/local/include/luajit-2.0/ \
    -pagezero_size 10000 \
    -image_base 100000000 \
    -o testcallback \
    src/testcallback.c 
$ ./testcallback
```
