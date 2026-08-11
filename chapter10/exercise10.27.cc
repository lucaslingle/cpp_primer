/*
In addition to ```unique```, the library defines a function named ```unique_copy```
that takes a third iterator denoting a destination into which to copy the unique 
elements. Write a program that uses unique_copy to copy the unique elements
into an initially empty list.
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<std::string> svec;
    std::list<std::string> slst;
    std::string word;
    while (std::cin >> word)
        svec.push_back(word);
    std::sort(svec.begin(), svec.end());
    std::unique_copy(svec.begin(), svec.end(), std::back_inserter(slst));
    std::for_each(slst.begin(), slst.end(), [](std::string &s) { std::cout << s << " "; });
    return 0;
}
