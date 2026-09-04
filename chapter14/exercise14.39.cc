/*
Revise the previous program to report the count of words 
that are sizes 1 through 9 and 10 or more.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
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

    Measurer meas(9);
    std::size_t short_count = 0;
    std::size_t long_count = 0;
    std::string word;
    while (inp >> word) {
        short_count += meas(word);
        long_count += !meas(word);
    }
    std::cout << short_count << std::endl;
    std::cout << long_count << std::endl;

    return 0;
}
