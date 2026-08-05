/*
Repeat the previous exercise, but compare elements in a list<int>
to a vector<int>.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

int main() {
    std::string line;
    std::istringstream elems;
    int elem;

    std::vector<int> v1;
    std::getline(std::cin, line);
    elems.str(line);
    while (elems >> elem)
        v2.push_back(elem);
    elems.clear();

    std::list<int> ls;
    std::getline(std::cin, line);
    elems.str(line);
    while (elems >> elem)
        v1.push_back(elem);
    elems.clear();
    std::vec<int> v2(ls.cbegin(), ls.cend());
    
    if (v1 == v2)
        std::cout << "v1 == v2" << std::endl;
    else
        std::cout << "v1 != v2" << std::endl;

    return 0;
}
