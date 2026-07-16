/*
Write a program containing the variables and assignments from the
previous exercise. Print the variables before and after the assignments 
to check whether your predictions in the previous exercise were correct.
If not, study the examples until you can convince yourself what led you 
to the wrong conclusion. 
*/

#include <iostream>

int main() {
    int i = 0, &r = i;
    auto a = r;

    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;

    a = 42;
    std::cout << "a: " << a << std::endl;

    b = 42;
    std::cout << "b: " << b << std::endl;

    c = 42;
    std::cout << "c: " << c << std::endl;

    d = 42;
    std::cout << "d: " << d << std::endl;

    e = 42;
    std::cout << "e: " << e << std::endl;

    f = 42;
    std::cout << "f: " << f << std::endl;
}