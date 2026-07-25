/*
Revise your program (from the previous exercise) to thrown an exception
if the second number is zero. Test your program with zero input to see
what happens on your system if you don't catch an exception.
*/

#include <iostream>
#include <stdexcept>

int main() {
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v2 == 0)
        throw std::runtime_error("cannot divide by zero!");
    std::cout << v1 / v2 << std::endl;
    return 0;
}
