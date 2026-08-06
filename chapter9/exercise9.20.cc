/*
Write a program to copy elements from a list<int> into two deques.
The even-valued elements should go into one deque and the odd ones into the other.
*/

#include <list>
#include <deque>

int main() {
    std::list<int> ls = {1, 2, 3, 7, 8, 9, 9, 9};
    std::deque<int> d1, d2;
    for (auto const &elem : ls) {
        if (elem % 2 == 0)
            d1.push_back(elem);
        else
            d2.push_back(elem);
    }
    return 0;
}
