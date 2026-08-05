/*
Write a program to determine whether two vector<int>s are equal.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::istringstream elems;
    int elem;

    std::vector<int> v1;
    std::getline(std::cin, line);
    elems.str(line);
    while (elems >> elem)
        v1.push_back(elem);
    elems.clear();

    std::vector<int> v2;
    std::getline(std::cin, line);
    elems.str(line);
    while (elems >> elem)
        v2.push_back(elem);
    elems.clear();

    if (v1 == v2)
        std::cout << "v1 == v2" << std::endl;
    else
        std::cout << "v1 != v2" << std::endl;

    return 0;
}
