/*
Write a function to open a file for input and read its contents into a
vector of strings, storing each line as a separate element in the vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad input format. expected: prog.o fname");

    std::ifstream inp(argv[1]);
    std::string line;
    std::vector<std::string> vec;
    if (inp)
        while (std::getline(inp, line))
            vec.push_back(line);
    for (auto s : vec)
        std::cout << s << std::endl;
    return 0;
}
