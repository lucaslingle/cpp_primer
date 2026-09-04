/*
Using library function objects and adaptors, define an expression to
(a) Count the number of values that are greater than 1024
(b) Find the first string that is not equal to `pooh`
(c) Multiply all the values by 2.
*/

#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std::placeholders;

int main() {
    std::vector<int> ivec = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    std::count_if(ivec.begin(), ivec.end(), std::bind(std::greater<int>(), _1, 1024));

    std::vector<std::string> svec = {"pooh", "roo", "eyore", "tiger"};
    std::find_if(
        svec.begin(), 
        svec.end(), 
        std::bind(std::not_equal_to<std::string>(), _1, "pooh")
    );

    std::vector<double> dvec = {0.0, 1.0, 2.718, 3.141, 42.0};
    std::transform(
        dvec.begin(), 
        dvec.end(), 
        dvec.begin(), 
        std::bind(std::multiplies<double>(), _1, 2.0)
    );

    return 0;
}