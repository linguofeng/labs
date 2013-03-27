#ifndef __BINDINGS_H__
#define __BINDINGS_H__

// Student对象提供给Lua的接口
Student* Student_new(void);
void Student_toString(Student*);
void Student_setName(Student*, const char*);
void Student_setAge(Student*, int);
void Student__gc(Student*);

#endif
