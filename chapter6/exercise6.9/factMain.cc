#include <iostream>
#include "Chapter6.h"

int main() {
    int n;
    std::cout << "Give me an integer n." << std::endl;
    std::cin >> n;
    std::cout << "The factorial of n is " << fact(n) << std::endl;
    return 0;
}
