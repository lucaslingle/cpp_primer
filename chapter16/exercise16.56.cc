/*
Write and test a variadic version of `errorMsg`.
*/

#include <iostream>
#include <sstream>
#include <string>

template <typename T> std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}

int main() {
    errorMsg(std::cout, "hello") << std::endl;
    errorMsg(std::cout, "hello", std::string("world")) << std::endl;
    errorMsg(std::cout, 1, 3.14, 'c', "hello", std::string("world")) << std::endl;
}
