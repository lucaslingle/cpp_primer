/*
Write a main function that takes two arguments.
Concatenate the supplied arguments and print the resulting string.
*/

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3)
        throw std::runtime_error("require two command line arguments.");
    std::string s1 = argv[1];
    std::string s2 = argv[2];
    std::cout << s1 + s2 << std::endl;
    return 0;
}
