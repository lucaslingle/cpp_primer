/*
Indicate which members of your Person class you would declare as public 
and which you would declare as private. Explain your choice.
*/

#include <iostream>
#include <string>

struct Person {
    private:
        // data members should be private to prevent unauthorized changes 
        // by class users
        std::string name;
        std::string address;
    public:
        // constructors and data member getters should be public to allow
        // class instantiation and data inspection. 
        Person() = default;
        Person(const std::string &n): name(n) { }
        Person(const std::string &n, const str::string &a): name(n), address(a) { }
        std::string get_name() const {
            return name;
        }
        std::string get_address() const {
            return address;
        }
}
