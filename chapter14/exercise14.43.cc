/*
Using library function objects, determine whether a given `int` value
is divisible by any element in a container of ints.
*/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std::placeholders;

int main() {
    std::vector<int> ivec = {2, 3, 4, 5, 6, 7, 8, 9};
    int quotient = 101;
    std::transform(
        ivec.begin(), 
        ivec.end(), 
        ivec.begin(),
        std::bind(std::modulus<int>(), quotient, _1)
    );
    bool answer = std::any_of(
        ivec.begin(),
        ivec.end(),
        std::bind(std::equal_to<int>(), 0, _1)
    );
    std::cout << answer << std::endl;
}