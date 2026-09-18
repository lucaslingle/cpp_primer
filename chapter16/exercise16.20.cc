/*
Rewrite the function from the previous exercise to use iterators
returned from `begin` and `end` to control the loop.
*/

#include <iostream>

template <typename C>
void print_container(std::ostream &ost, const C &container) {
    auto b = container.begin();
    auto e = container.end();
    for (; b != e; ++b)
        ost << *b << " ";
}
