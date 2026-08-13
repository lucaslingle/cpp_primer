/*
Write a program that stores the excluded words in a vector instead of in a set.
What are the advantages to using a set?
*/

// a vector requires a linear-time scan to identify items it holds.
// a set probably uses binary search since the items are sorted by key.
// so a set has the advantage of speed.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::map<std::string, std::string::size_type> word_count;
    std::string word;
    std::vector<std::string> exclude = {
        "The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"
    };
    while (std::cin >> word)
        if (std::find(exclude.begin(), exclude.end(), word) == exclude.end())
            ++word_count[word];
    for (const auto &kv : word_count)
        std::cout << kv.first << " occurs " << kv.second << " time(s)." << std::endl;
    return 0;
}
