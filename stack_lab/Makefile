
CC = g++
CXXFLAGS = -g -Wall
LDFLAGS = 

all:
	mkdir -p {bin,obj}
	${CC} ${CXXFLAGS} -c src/main.cpp -o obj/main.o
	${CC} ${CXXFLAGS} obj/main.o -o bin/main

clean:
	rm -rf bin obj
