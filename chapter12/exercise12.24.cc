/*
Write a program that reads a string from the standard input 
into a dynamically allocated character array. 
Describe how your program handles varying size inputs.
Test your program by giving it a string of data longer 
than the array size you've allocated.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <new>

int main() {
    std::string line;
    std::getline(std::cin, line);

    char *dyna = new char[line.size()+1];
    std::strcpy(dyna, line.c_str());

    std::cout << dyna << std::endl;
    delete [] dyna;
    return 0;
}
