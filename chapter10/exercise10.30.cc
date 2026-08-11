/*
Use stream iterators, sort, and copy to read a sequence of integers
from the standard input, sort them, and write them back to standard output.
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

    std::ostream_iterator<std::string> output_iter(std::cout, " ");
    std::copy(vec.begin(), vec.end(), output_iter);
    std::cout << std::endl;

    return 0;
}
