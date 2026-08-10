/*
Use accumulate to sum the elements in a vector<int>
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::vector<int> container;
    std::istringstream ist(line);
    int val;
    while (ist >> val)
        container.push_back(val);
    
    std::cin >> val;
    std::cout << std::accumulate(container.cbegin(), container.cend(), 0) << std::endl;
    return 0;
}
