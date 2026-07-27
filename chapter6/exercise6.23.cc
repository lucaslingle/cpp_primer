/*
Write your own versions of each of the print functions presented in this section.
Call each of these functions to print i and j defined as follows:
```
int i = 0, j[2] = {0, 1};
```
*/

#include <iostream>
#include <cstddef>

void print(int i) {
    std::cout << i << std::endl;
}

void print(const int ia[], std::size_t size) {
    for (std::size_t i = 0; i != size; ++i)
        std::cout << ia[i] << std::endl;
}

int main() {
    int i = 0, j[2] = {0, 1};
    print(i);
    print(j, 2);
    return 0;
}
