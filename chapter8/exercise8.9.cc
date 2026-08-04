/*
Use the function you wrote for the exercise 8.1 to print 
the contents of an istringstream object.
*/

#include <sstream>
#include <iostream>
#include <string>

std::istringstream &read_func(std::istringstream &ist) {
    std::string word;
    while (ist >> word)
        std::cout << word << std::endl;
    ist.clear();
    return ist;
}
