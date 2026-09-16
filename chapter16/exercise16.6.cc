/*
How do you think the library `begin` and `end` functions that take
an array argument work? Define your own versions of these functions.
*/

#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>
T* my_begin(T (&ta)[N]) {
    return ta;
}

template <typename T, std::size_t N>
T* my_end(T (&ta)[N]) {
    return ta + N;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char arr2[5] = {'h', 'e', 'l', 'l', 'o'};

    std::cout << my_begin(arr) - arr << " " << my_end(arr) - arr << std::endl;
    std::cout << my_begin(arr2) - arr2 << " " << my_end(arr2) - arr2 << std::endl;

    return 0;
}