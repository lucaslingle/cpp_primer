/*
Write a program to compare two arrays for equality.
Write a similar program to compare two vectors.
*/

#include <iostream>
#include <vector>
#include <cstddef>

int equal_arr(int a1[], int a2[], int l1, int l2) {
    if (l1 != l2)
        return 0;
    for (std::size_t i = 0; i != l1; ++i)
        if (a1[i] != a2[i])
            return 0;
    return 1;
}

int equal_vec(std::vector<int> v1, std::vector<int> v2) {
    return v1 == v2;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 2, 3, 4};
    int arr4[] = {1, 2, 3, 5};
    // expecting 1, 0, 0 output
    std::cout << equal_arr(arr1, arr2, 3, 3) << std::endl; 
    std::cout << equal_arr(arr2, arr3, 3, 4) << std::endl;
    std::cout << equal_arr(arr3, arr4, 4, 4) << std::endl;

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 2, 3};
    std::vector<int> vec3 = {1, 2, 3, 4};
    std::vector<int> vec4 = {1, 2, 3, 5};
    // expecting 1, 0, 0 output
    std::cout << equal_vec(vec1, vec2) << std::endl; 
    std::cout << equal_vec(vec2, vec3) << std::endl;
    std::cout << equal_vec(vec3, vec4) << std::endl;
}
