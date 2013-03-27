#ifndef __HEADER_H__
#define __HEADER_H__

void sayHi(void);

int add(int x, int y);

typedef struct {
    char *name;
    int age;
} Student;

void call(Student*);

#endif
