/*
In the final example in this section what would happen if we did not
assign the result of ```insert``` to ```begin```? Write a program that
omits this assignment to see if your explanation was correct.

reference code:
```
while (begin != v.end()) {
    // do some processing
    ++begin;
    begin = v.insert(begin, 42);
    ++begin;
}
```
*/

// primary: if a reallocation occurs, the begin iterator may be invalidated.
// secondary: if we omit the begin = v.insert, we also skip over an element after each inserted one.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4};
    auto begin = v.begin();
    while (begin != v.end()) {
        std::cout << *begin << " ";
        ++begin;
        begin = v.insert(begin, 42);
        ++begin;
    }
    std::cout << std::endl;
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> v2 = {0, 1, 2, 3, 4};
    auto begin2 = v2.begin();
    while (begin2 != v2.end()) {
        std::cout << *begin2 << " ";
        ++begin2;
        v2.insert(begin2, 42);
        ++begin2;
    }
    std::cout << std::endl;
    for (auto i : v2)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
