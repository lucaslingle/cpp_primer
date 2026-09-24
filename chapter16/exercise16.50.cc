/*
Define the functions from the previous exercise so that they print an 
identifying message. Run the code from that exercise. If the calls
behave differently from what you expected, make sure you understand why.

reference code:
```
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

g(42);
g(p);
g(ci);
g(p2);

f(42);
f(p);
f(ci);
f(p2);
```
*/

// expectations - given in previous exercise answer.
//
// g(42) - No way to deduce a pointer type T* from this, resolves to g(T), T = int.
// g(p) - Either g(T) with T = int*, or g(T*) with T = int. 
//     The second is more specific; resolves to g(T*), T = int.
// g(ci) - No way to deduce a pointer type T* from this, and top-level const is dropped,
//    resolves to g(T), T = int.
// g(p2) - Either g(T) with T = const int*, or g(T*) with T = const int. 
//    The second is more specific; resolves to g(T*), T = const int.
//
// f(42) - No way to deduce a pointer type T* from this, resolves to f(T), T = int.
// f(p) - Either f(T) with T = int* or f(const T*) with T = int. 
//    Second option adds low level const, first is exact match. 
//    Resolves to f(T) with T = int*.
// f(ci) - No way to deduce a pointer type T* from this. Top level const is dropped. 
//    Resolves to f(T), T = int.
// f(p2) - Either f(T) with T = const int*, or f(const T*) with T = int. Low level const is kept. 
//    The second is more specific; resolves to f(const T*), T = int.

#include <iostream>

template <typename T> void f(T) {
    std::cout << "f(T)" << std::endl;
}
template <typename T> void f(const T*) {
    std::cout << "f(const T*)" << std::endl;
}
template <typename T> void g(T) {
    std::cout << "g(T)" << std::endl;
}
template <typename T> void g(T*) {
    std::cout << "g(T*)" << std::endl;
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    std::cout << "expected: g(T), actual: ";
    g(42);
    std::cout << "expected: g(T*), actual: ";
    g(p);
    std::cout << "expected: g(T), actual: ";
    g(ci);
    std::cout << "expected: g(T*), actual: ";
    g(p2);

    std::cout << "expected: f(T), actual: ";
    f(42);
    std::cout << "expected: f(T), actual: ";
    f(p);
    std::cout << "expected: f(T), actual: ";
    f(ci);
    std::cout << "expected: f(const T*), actual: ";
    f(p2);
}
