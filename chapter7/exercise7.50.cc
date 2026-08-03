/*
Determine whether any of your Person class constructors should be explicit. 
*/

// theres only one constructor that could be marked explicit,
// Person(const std::string &n)
// and i think it would be good to mark it as such,
// so people dont go around doing things like calling
// read and print while passing a string instead of a Person argument. 

#include <iostream>
#include <string>

class Person {
    friend std::istream &read(std::istream &ist, Person &person);
    friend std::ostream &print(std::ostream &ost, const Person &person);
    private:
        std::string name;
        std::string address;
    public:
        Person() = default;
        explicit Person(const std::string &n): name(n) { }
        Person(const std::string &n, const str::string &a): name(n), address(a) { }
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


