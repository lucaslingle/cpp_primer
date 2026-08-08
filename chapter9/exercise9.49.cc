/*
A letter has an ascender if as with d or f, 
part of the letter extends above the middle of the line.
A letter has a descender if as with p or g, 
part of the letter extends below the line.
Write a program that reads a file containing words
and reports the longest word that contains neither 
ascenders nor descenders.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>

bool contains_ascenders(const std::string &s) {
    std::string ascenders = "bdfhklt";
    return s.find_first_of(ascenders) != std::string::npos;
}

bool contains_descenders(const std::string &s) {
    std::string descenders = "gjpqy";
    return s.find_first_of(descenders) != std::string::npos;
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad format. expected: prog.o fname");

    std::ifstream inp(argv[1]);
    std::string word;
    std::string longest;
    std::string::size_type maxlen = 0;
    while (inp >> word) {
        if (!contains_ascenders(word) && !contains_descenders(word)) {
            if (word.size() > maxlen) {
                maxlen = word.size();
                longest = word;
            }
        }
    }
    std::cout << longest << std::endl;
    return 0;
}
