/*
Extend your program to ignore case and punctuation.
For example, "example.", "example,", and "Example" 
should all increment the same counter.
*/

#include <iostream>
#include <string>
#include <map>
#include <cctype>

std::string clean(const std::string &s) {
    std::string output;
    for (unsigned char c : s)
        if (std::isalnum(c))
            output += std::tolower(c);
    return output;
}

int main() {
    std::map<std::string, std::string::size_type> word_count;
    std::string word;
    while (std::cin >> word)
        ++word_count[clean(word)];
    for (const auto &kv : word_count)
        std::cout << kv.first << " occurs " << kv.second << " time(s)." << std::endl;
    return 0;
}
