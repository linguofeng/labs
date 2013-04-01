extern "C" test

===

### build1

```bash
$ gcc -c -Iinclude src/utils.c 
$ g++ -Iinclude utils.o src/main.cpp
```

### build2 error

```bash
$ g++ -c -Iinclude src/utils.c 
$ g++ -Iinclude utils.o src/main.cpp
```

### build3

```bash
$ gcc -c -Iinclude src/utils1.cpp 
$ g++ -Iinclude utils.o src/main.cpp
```

### build4

```bash
$ g++ -c -Iinclude src/utils1.cpp 
$ g++ -Iinclude utils.o src/main.cpp
```
