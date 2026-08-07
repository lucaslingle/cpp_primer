/*
Write a program that initializes a string from a vector<char>.
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> vec = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    std::string s(vec.cbegin(), vec.cend());
    std::cout << s << std::endl;
    return 0;
}
