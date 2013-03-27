#include "Student.h"
#include <iostream>
#include <string.h>

Student::Student(): name(NULL) {
    
}

Student::~Student() {
    
}

void Student::toString() {
    std::cout << "name: " << name << " age: " << age << std::endl;
}

void Student::setName(const char* name) {
    if (this->name != NULL) {
        delete this->name;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Student::setAge(int age) {
    this->age = age;
}
