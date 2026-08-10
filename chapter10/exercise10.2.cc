/*
Repeat the previous exercise using a list of strings instead.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::list<std::string> container;
    std::istringstream ist(line);
    std::string val;
    while (ist >> val)
        container.push_back(val);
    
    std::cin >> val;
    std::cout << std::count(container.cbegin(), container.cend(), val) << std::endl;
    return 0;
}
