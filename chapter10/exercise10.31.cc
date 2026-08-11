/*
Update the program from the previous exercise so that it prints only
the unique elements. Your program should use ```unique_copy```.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    std::istream_iterator<std::string> input_iter(std::cin), eof;
    std::vector<std::string> vec(input_iter, eof);
    std::sort(vec.begin(), vec.end());

    std::vector<std::string> vec2;
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(vec2));

    std::ostream_iterator<std::string> output_iter(std::cout, " ");
    std::copy(vec2.begin(), vec2.end(), output_iter);
    std::cout << std::endl;

    return 0;
}
