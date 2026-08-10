/*
The library defines an algorithm named ```partition``` that takes a predicate and 
partitions the container so values for which the predicate is true 
appear in the first part and those for which the predicate is false 
appear in the second. 

The algorithm returns an iterator just past the last element for which 
the predicate returned true. 

Write a function that takes a string and returns a bool indicating 
whether string has five characters or more. Use that function to partition
```words```. Print the elements that have five or more characters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_longword(const std::string &s) {
    return s.size() >= 5;
}

int main() {
    std::string val;
    std::vector<std::string> container;
    while (std::cin >> val)
        container.push_back(val);

    auto stop = std::partition(container.begin(), container.end(), is_longword);
    auto start = container.begin();
    while (start != stop) {
        std::cout << *start << " ";
        ++start;
    }
    std::cout << std::endl;

    return 0;
}
