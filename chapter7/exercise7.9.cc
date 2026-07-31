/*
Add operations to read and print Person objects 
to the code you wrote in exercises 7.4 and 7.5.
*/

#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string get_name() const {
        return name;
    }
    std::string get_address() const {
        return address;
    }
};

std::istream &read(std::istream &ist, Person &person) {
    ist >> person.name >> person.address;
    return ist;
}

std::ostream &print(std::ostream &ost, const Person &person) {
    ost << person.name << " @ " << person.address;
    return ost;
}
