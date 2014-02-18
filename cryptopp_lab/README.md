
## build cryptopp static library

```bash
$ axel -n 5 http://www.cryptopp.com/cryptopp562.zip
$ unzip cryptopp562.zip
$ cd cryptopp562
$ make static
```

## build test

```bash
$ g++ \
    -I cryptopp562 \
    -L cryptopp562 \
    -l cryptopp \
    -o bin/main \
    src/main.cpp
$ ./bin/main
```
