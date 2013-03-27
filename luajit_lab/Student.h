#ifndef __STUDENT_H__
#define __STUDENT_H__

class Student {
    public:
        Student();
        ~Student();
        void toString(void);
        void setName(const char* name);
        void setAge(int age);
    private:
        char* name;
        int age;
};

#endif
