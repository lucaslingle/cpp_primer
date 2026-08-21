/*
A good way to understand copy-control members and constructors is
to define a simple class with these members in which each member prints its name:
```
struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const &X) { std::cout << "X(const &X)" << std::endl; }
};
```
Add the copy-assignment operator and destructor to X and write a program using X
objects in various ways. Pass them as nonreference and reference parameters.
Dynamically allocate them. Put them in containers, and so forth.
Study the output until you are certain you understand when and why each copy-control
member is used. As you read the output, remember that the compiler can omit
calls to the copy constructor. 
*/

// got output:
//
// Creating X
// 	default constructor
// Passing by value
// 	copy constructor
// 	destructor
// Passing by reference
// Adding to container
// 	copy constructor
// Program end
// 	destructor
// 	destructor

#include <iostream>
#include <vector>

struct X {
    X() { std::cout << "\tdefault constructor" << std::endl; }
    X(const X& x) { std::cout << "\tcopy constructor" << std::endl; }
    X& operator=(const X& x) { 
        std::cout << "\tcopy-assign operator" << std::endl; 
        return *this; 
    }
    ~X() { std::cout << "\tdestructor" << std::endl; }
};

void byval(X x) { }
void byref(X &x) { }

int main() {
    std::cout << "Creating X" << std::endl;
    X x;

    std::cout << "Passing by value" << std::endl;
    byval(x);

    std::cout << "Passing by reference" << std::endl;
    byref(x);

    std::cout << "Adding to container" << std::endl;
    std::vector<X> vec;
    vec.push_back(x);
    
    std::cout << "Program end" << std::endl;
    return 0;
}