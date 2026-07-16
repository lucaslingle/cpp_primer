/*
Determine the types deduced in each of the following definitions.
Once you've figured out the types, write a program to see if you were correct:
```
const int i = 42;
auto j = i; 
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;
```
*/

// i is const int.
// j is int.
// k is const int&.
// p is const int*.
// j2 is const int.
// k2 is const int&.

#include <iostream>

int main() {
    const int i = 42;
    auto j = i; 
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    std::cout << "type of i: " << typeid(i).name() << std::endl;
    std::cout << "type of j: " << typeid(j).name() << std::endl;
    std::cout << "type of k: " << typeid(k).name() << std::endl;
    
    std::cout << "type of p: " << typeid(p).name() << std::endl;
    std::cout << "type of j2: " << typeid(j2).name() << std::endl;
    std::cout << "type of k2: " << typeid(k2).name() << std::endl;

    // I ran this and thought it didnt work, but gemini says
    // the printed output might be mangled (e.g., i for int, PKi for pointer to const int), 
    // depending on your compiler.
}
