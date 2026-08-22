/*
Does your ```Employee``` class need to define its own versions
of the copy-control members? If so, why? If not, why not?
Implement whatever copy-control members you think ```Employee``` needs.
*/

// the employee id should stay the same if the new class refers
// to the same employee as the one it was copied from.
// but otherwise i'd add the stuff commented out below.

// an argument can also be made for disallowing copy and assign for
// the Employee class, since instances represent unique entities.
// i've defined a deleted copy constructor and deleted copy-assign operator below.

#include <string>
using std::string;

class Employee {
    public:
        Employee(): id(counter++) { }
        Employee(const string &name): name(name), id(counter++) { }
        // Employee(const Employee &e): name(e.name), id(counter++) { }
        // Employee& operator=(const Employee &e) { 
        //     name = e.name;
        //     id = counter++;
        // }
        Employee(const Employee &e) = delete;
        Employee& operator=(const Employee &e) = delete;
    private:
        static inline unsigned counter = 0;
        string name;
        unsigned id;
};
