/*
Write a function that takes a reference to a container and 
prints the elements in that container. Use the container's `size_type` 
and `size` members to control the loop that prints the elements.
*/

#include <iostream>

template <typename C>
void print_container(std::ostream &ost, const C &container) {
    auto begin = container.begin();
    for (typename C::size_type i = 0; i != container.size(); ++i) {
        ost << *begin << " ";
        ++begin;
    }
}
