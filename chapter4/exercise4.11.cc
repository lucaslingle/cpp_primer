/*
Write an expression that tests four values, a, b, c, and d,
and ensures that a is greater than b, which is greater than c, which is greater than d.
*/

#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > b && b > c && c > d)
        std::cout << "a > b > c > d" << std::endl;
    else
        std::cout << "!(a > b > c > d)" << std::endl;
    return 0;
}
