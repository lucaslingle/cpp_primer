/*
Write a program to assign the elements from a list of char* pointers
to C-style character strings to a vector of strings.
*/

#include <list>
#include <vector>
#include <string>
#include <iostream>

int main() {
    char hello[] = "hello\0";
    char world[] = "world\0";
    std::list<char*> src = {hello, world};
    std::vector<std::string> dest;
    dest.assign(src.cbegin(), src.cend());

    for (auto &elem : dest)
        std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}
