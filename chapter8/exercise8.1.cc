/*
Write a function that takes and returns an istream&. The function should
read the stream until it hits end-of-file. The function should print
what it reads to the standard output. Reset the stream so that it is valid
before returning the stream.
*/

#include <iostream>
#include <string>

std::istream &read_func(std::istream &ist) {
    std::string word;
    while (ist >> word)
        std::cout << word << std::endl;
    ist.clear();
    return ist;
}
