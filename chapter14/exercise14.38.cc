/*
Write a class that tests whether the length of a given `string`
matches a given bound. Use that object to write a program to report
how many words in an input file are of sizes 1 through 10 inclusive.
*/

#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>

class Measurer {
public:
    Measurer(std::size_t n): sz(n) { }
    bool operator()(const std::string &s) const { 
        return s.size() <= sz; 
    }
private:
    std::size_t sz;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "bad format. expected: prog.o fname" << std::endl;
        return -1;
    }

    std::ifstream inp(argv[1]);
    if (!inp.is_open()) {
        std::cerr << "bad file read." << std::endl;
        return -2;
    }

    Measurer meas(10);
    std::size_t count = 0;
    std::string word;
    while (inp >> word)
        count += meas(word);
    std::cout << count << std::endl;

    return 0;
}
