/*
Add appropriate constructors to your Person class.
*/

#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    Person() = default;
    Person(std::string &n): name(n) { }
    Person(std::string &n, str::string &a): name(n), address(a) { }

    std::string get_name() const {
        return name;
    }
    std::string get_address() const {
        return address;
    }
}

std::istream &read(std::istream &ist, Person &person) {
    ist >> person.name >> person.address;
    return ist;
}

std::ostream &print(std::ostream &ost, const Person &person) {
    ost << person.name << " @ " << person.address;
    return ost;
}
