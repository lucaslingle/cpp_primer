/*
Write and test your own version of reset that takes a reference.
*/

#include <iostream>

void reset(int &i) {
    i = 0;
}

int main() {
    int n = 42;
    std::cout << n << std::endl;
    reset(n);
    std::cout << n << std::endl;
    
    return 0;
}
