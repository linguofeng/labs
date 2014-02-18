#include <iostream>
#include <fstream>
#include "Person.pb.h"

using namespace std;

void write()
{
    Person person;
    person.set_name("John Doe");
    person.set_id(1234);
    person.set_email("jdoe@example.com");
    fstream output("myfile", ios::out | ios::binary);
    person.SerializeToOstream(&output);
}

void read()
{
    fstream input("myfile", ios::in | ios::binary);
    Person person;
    person.ParseFromIstream(&input);
    cout << "Name: " << person.name() << endl;
    cout << "E-mail: " << person.email() << endl;
}

int main()
{
    write();
    read();
    return 0;
}
