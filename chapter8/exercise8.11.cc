/*
The program in this section defined its istringstream object inside
the outer while loop. What changes would you make if ```record``` were defined
outside that loop? Rewrite the program, moving the definition of ```record```
outside the while, and see whether you thought of all the changes that are needed.
*/

// we just gotta declare the istringstream object without a direct initialization
// and then call .str(line) to write each line to it before reading out each word
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main() {
    // original from book
    // std::string line, word;
    // std::vector<PersonInfo> people;
    // while (std::getline(std::cin, line)) {
    //     PersonInfo info;
    //     std::istringstream record(line);
    //     record >> info.name;
    //     while (record >> word)
    //         info.phones.push_back(word);
    //     people.push_back(info);
    // }

    // rewritten
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(std::cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    return 0;
}
