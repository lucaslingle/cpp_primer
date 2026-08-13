/*
Rewrite the word-counting program from p. 421 to use insert instead of 
subscripting. Which program do you think is easier to read and write?
Explain your reasoning.
*/

// subscripting is easier, it is a single line that handles both cases
// of whether the key is present or not. 
#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, std::string::size_type> word_count;
    std::string word;
    while (std::cin >> word) {
        // ++word_count[word];
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &kv : word_count)
        std::cout << kv.first << " occurs " << kv.second << " time(s)." << std::endl;
    return 0;
}
