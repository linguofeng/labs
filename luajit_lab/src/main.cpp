#include <iostream>
#include <string.h>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class Student {
    public:
        void toString(void) {
            std::cout << "name: " << name << " age: " << age << std::endl;
        }

        void setName(const char* name) {
            delete this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        void setAge(int age) {
            this->age = age;
        }

    private:
        char* name;
        int age;
};

extern "C" {

Student* Student_new(void) {
    std::cout << "Student_new" << std::endl;
    return new Student();
}

void Student__gc(Student* self) {
    std::cout << "Student__gc" << std::endl;
    delete self;
}

void Student_setName(Student* stu, const char* name) {
    std::cout << "Student_setName" << std::endl;
   stu->setName(name); 
}

void Student_setAge(Student* stu, int age) {
    std::cout << "Student_setAge" << std::endl;
    stu->setAge(age);
}

void Student_toString(Student* stu) {
    std::cout << "Student_toString" << std::endl;
    stu->toString();
}

int main(void) {
    //std::cout << "Hello World!!" << std::endl;
    
    lua_State* L = luaL_newstate();   
    luaL_openlibs(L);
    luaL_dofile(L, "../luascripts/testcpp.lua");
    lua_close(L);
    
    return 0;
}

}
