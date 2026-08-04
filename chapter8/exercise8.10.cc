/*
Write a program to store each line from a file in a vector<string>.
Now use an istringstream to read each element from the vector a word at a time.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad format. expected: prog.o fname");

    std::ifstream inp(argv[1]);
    std::vector<std::string> vec;
    std::string line;
    while (std::getline(inp, line))
        vec.push_back(line);
    for (auto l : vec) {
        std::istringstream iss(l);
        std::string word;
        while (iss >> word)
            std::cout << word << std::endl;
    }

    return 0;
}
