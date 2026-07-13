/*
Write code to change the value of a pointer.
Write code to change the value to which a pointer points.
*/

#include <iostream>

int main() {
    int i = 123;
    int *p1 = nullptr;

    // chg value of a ptr
    p1 = &i;
    // should print 123
    std::cout << *p1 << std::endl;

    // chg value to which ptr points
    *p1 = 456;
    // should print 456
    std::cout << i << std::endl;
}
