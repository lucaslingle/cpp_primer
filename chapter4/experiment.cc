/*
p. 150: The arrow operator requires a pointer operand and yields an lvalue.
The dot operator yields an lvalue if the object from which the member is fetched 
is an lvalue; otherwise the result is an rvalue.
*/

#include <iostream>

struct point { int x; int y; };
typedef struct point Point;

Point make_point() {
    Point origin = {0, 0}; 
    return origin;
}

int main() {
    // lvalue
    Point p = make_point();
    std::cout << (p.x = 100) << std::endl;

    // rvalue
    std::cout << (make_point().x = 100) << std::endl;

    return 0;
}
