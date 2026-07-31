/*
Provide operations in your Person class to return the name and address.
Should these functions be const? Explain your choice below.
*/

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

// both member functions should be const because they dont modify the class.
