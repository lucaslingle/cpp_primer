/*
Write a lambda that captures a local int variable and decrements that 
variable until it reaches 0. Once the variable is 0, additional calls 
should no longer decrement the variable. The lambda should return a bool
that indicates whether the captured variable is 0.
*/

#include <iostream>

int main() {
    int i = 3;
    auto f = [&i]() -> bool { if (i > 0) { --i; return true; } else { return false; } };
    while (i > 0) {
        std::cout << i << std::endl;
        f();
    }
    return 0;
}
