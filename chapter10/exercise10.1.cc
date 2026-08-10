/*
The ```algorithm``` header defines a function named ```count``` that, 
like ```find```, takes a pair of iterators and a value. ```count``` returns a count
of how often that value appears. Read a sequence of ints into a vector
and print the count of how many elements have a given value.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::vector<int> container;
    std::istringstream ist(line);
    int val;
    while (ist >> val)
        container.push_back(val);
    
    std::cin >> val;
    std::cout << std::count(container.cbegin(), container.cend(), val) << std::endl;
    return 0;
}
