#include "Student.h"

extern "C" {
#include "bindings.h"
}

extern "C" {

    Student* Student_new(void) {
        return new Student();        
    }

    void Student_toString(Student* stu) {
        stu->toString();
    }
    
    void Student_setName(Student* stu, const char* name) {
        stu->setName(name);
    }

    void Student_setAge(Student* stu, int age) {
        stu->setAge(age);
    }
    
    void Student__gc(Student* stu) {
        delete stu;
    }

}
