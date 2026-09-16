/*
Write and test your own versions of the `compare` function.
*/

#include <iostream>
#include <string>

template <typename T>
int compare(const T& lhs, const T& rhs) {
    if (lhs < rhs)
        return -1;
    if (rhs < lhs)
        return 1;
    return 0;
}

int main() {
    std::string hello = "hello";
    std::string helloworld = "hello world";

    std::cout << "'" << hello << "' < '" << helloworld << "': "
              << compare(hello, helloworld) << std::endl;
    
    std::cout << "100 < 10: " << compare(100, 10) << std::endl;
    return 0;
}