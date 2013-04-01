extern "C" test

===
## 把C函数或变量写在.c文件中时

如果在.cpp中调用应该加extern "C",否则无法编译。

### build1 success

```bash
$ gcc -c -Iinclude src/utils.c 
$ g++ -Iinclude utils.o src/main.cpp
```

### build2 error

```bash
$ g++ -c -Iinclude src/utils.c 
$ g++ -Iinclude utils.o src/main.cpp
```

## 把C函数或变量写在.cpp文件中时

应该同时使用或者同时不使用extern "C",注意如果该函数需要导出的应该加extern "C",如luajit中的绑定。
使用extern "C"的意义在于该函数在使用g++编译时是否导出外部使用，如编译成动态库、luajit绑定时等。

### build1

```bash
$ gcc -c -Iinclude src/utils1.cpp 
$ g++ -Iinclude utils.o src/main.cpp
```

### build2

```bash
$ g++ -c -Iinclude src/utils1.cpp 
$ g++ -Iinclude utils.o src/main.cpp
```
