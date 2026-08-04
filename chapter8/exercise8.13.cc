/*
Rewrite the phone number program from this section to read 
from a named file rather than from cin.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

bool valid(std::string);
std::string format(std::string);

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad format. expected: prog.o fname");
    std::ifstream inp(argv[1]);

    std::string line, word;
    std::vector<PersonInfo> people;
    while (std::getline(inp, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums))
                badNums << " " << nums;
            else 
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            std::cout << entry.name << " " << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
        
    }
}
