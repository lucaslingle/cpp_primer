/*
Test your function by calling it, passing cin as an argument.
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

int main() {
    read_func(std::cin);
    std::cout << "is good: " << std::cin.good() << std::endl;
    return 0;
}
