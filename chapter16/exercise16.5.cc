/*
Write a template version of the `print` function from p. 217
that takes a reference to an array and can handle 
arrays of any size and element type.

reference code:
```
void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i)
        std::cout << ia[i] << std::endl;
}
```
*/

#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>
void my_print(const T (&ta)[N]) {
    for (size_t i = 0; i != N; ++i)
        std::cout << ta[i] << std::endl;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char arr2[5] = {'h', 'e', 'l', 'l', 'o'};

    my_print(arr);
    my_print(arr2);

    return 0;
}