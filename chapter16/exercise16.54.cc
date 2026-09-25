/*
What happens if we call `print` on a type that doesn't have a `<<` operator?
*/

// i predict overload resolution and type deduction will still work, 
// but that it will error out because `operator<<` is not defined for the given type.
// let's test it. 

#include <iostream>
#include <string>

template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

struct NoDefinedArrowArrowOperator {
    int foo = 123;
};

int main() {
    print(std::cout, "hello") << std::endl;
    print(std::cout, "hello", std::string("world")) << std::endl;
    print(std::cout, 1, 3.14, 'c', "hello", std::string("world")) << std::endl;
    print(std::cout, "hello", NoDefinedArrowArrowOperator()) << std::endl;
    /* yep, got:
          |  ;
    exercise16.54.cc:18:15: error: invalid operands to binary expression ('std::ostream' (aka 'basic_ostream<char>') and 'const NoDefinedArrowArrowOperator')
       18 |     return os << t;
          |            ~~ ^  ~
    */
}