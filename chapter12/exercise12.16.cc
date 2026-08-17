/*
Compilers don't always give easy-to-understand error messages if we
attempt to copy or assign a unique_ptr. Write a program that contains
these errors to see how your compiler diagnoses them.
*/

#include <memory>
#include <string>
using std::unique_ptr;
using std::string;

int main() {
    unique_ptr<string> p1(new string("Hello World"));

    // unique_ptr<string> p2(p1);  // error of some kind, no copy for unique_ptr
    //
    // got:
    // error: call to implicitly-deleted copy constructor of 'unique_ptr<string>' (aka 'unique_ptr<basic_string<char>>')

    unique_ptr<string> p3;
    p3 = p1;  // error of some other kind, no assign for unique_ptr.
    //
    // got: 
    // error: object of type 'unique_ptr<string>' (aka 'unique_ptr<basic_string<char>>') cannot be assigned because its copy assignment operator is implicitly deleted

    return 0;
}
