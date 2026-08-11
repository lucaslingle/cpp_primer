/*
Write a program that takes the names of an input file and two output files.
The input file should hold integers. Using an istream_iterator, read the
input file. Using ostream_iterators, write the odd integers to the first
output file. Each value should be followed by a space.
Write the even numbers into the second file. Each of these values should
be placed on a separate line.
*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <stdexcept>

int main(int argc, char *argv[]) {
    if (argc != 4)
        throw std::runtime_error("bad format. expected: prog.o inp outp1 outp2");

    std::ifstream inp(argv[1]);
    std::ofstream outp1(argv[2]);
    std::ofstream outp2(argv[3]);

    std::istream_iterator<int> input_iter(inp), eof;
    std::ostream_iterator<int> output1_iter(outp1, " ");
    std::ostream_iterator<int> output2_iter(outp2, "\n");

    while (input_iter != eof) {
        if (*input_iter % 2 == 1)
            *output1_iter++ = *input_iter;
        else
            *output2_iter++ = *input_iter;
        ++input_iter;
    }
    return 0;
}