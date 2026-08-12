/*
Write your own version of the word-counting program.
*/

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, std::string::size_type> word_count;
    std::string word;
    while (std::cin >> word)
        ++word_count[word];
    for (const auto &kv : word_count)
        std::cout << kv.first << " occurs " << kv.second << " time(s)." << std::endl;
    return 0;
}
