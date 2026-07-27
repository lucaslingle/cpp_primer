/*
p 214: using a plain reference instead of ref too const unduly limits 
the type of arguments that can be used with the function. 
as we've just seen we cannot use a plain const object, a literal, or
*an object that requires conversion* to a plain reference parameter.
*/

#include <iostream>

void print(const int &i) {
    std::cout << i << std::endl;
}

int main() {
    double d = 3.14;
    print(d);
    return 0;
}
