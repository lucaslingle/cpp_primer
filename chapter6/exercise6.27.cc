/*
Write a function that takes an initializer_list<int> 
and produces a sum of elements in the list.
*/

#include <iostream>
#include <initializer_list>

int summation(std::initializer_list<int> il) {
    int sum = 0;
    for (auto elem : il)
        sum += elem;
    return sum;
}

int main() {
    int sum = summation({0, 1, 2, 3, 4});
    std::cout << "sum: " << sum << std::endl;
    return 0;
}
