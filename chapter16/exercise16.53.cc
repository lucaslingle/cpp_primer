/*
Write your own version of the `print` functions and test them by 
printing one, two, and five arguments, each of twich should have different types.
*/

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

int main() {
    print(std::cout, "hello") << std::endl;
    print(std::cout, "hello", std::string("world")) << std::endl;
    print(std::cout, 1, 3.14, 'c', "hello", std::string("world")) << std::endl;
}