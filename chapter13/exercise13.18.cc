/*
Define an ```Employee``` class that contains an employee name
and a unique employee identifier. Give the class a default constructor
and a constructor that takes a ```string``` representing the employee's name.
Each constructor should generate a unique ID by incrementing a static data member.
*/

#include <string>
using std::string;

class Employee {
    public:
        Employee(): id(counter++) { }
        Employee(const string &name): name(name), id(counter++) { }
    private:
        static inline unsigned counter = 0;
        string name;
        unsigned id;
};
