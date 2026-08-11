/*
Write a program using string iterators to read a text file into a vector of strings.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <algorithm>

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad format. expected: prog.o output_fname");

    std::ifstream inp(argv[1]);
    std::istream_iterator<std::string> input_iter(inp), eof;
    std::vector<std::string> vec(input_iter, eof);
    
    std::ostream_iterator<std::string> output_iter(std::cout, "\n");
    std::copy(vec.begin(), vec.end(), output_iter);
    return 0;
}
