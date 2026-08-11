/*
Rewrite the program to count words of size 6 or less,
using functions in place of the lambdas.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool check_size(const std::string &s, std::vector<std::string>::size_type sz) {
    return s.size() < sz;
}

void smallies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
    // sort alphabetically
    std::sort(words.begin(), words.end());
    // move duplicates to the end
    auto end_unique = std::unique(words.begin(), words.end());
    // erase duplicates
    words.erase(end_unique, words.end());
    // print number of small words
    int count = std::count_if(words.begin(), words.end(), 
                              std::bind(check_size, _1, sz + 1));
    std::cout << "got " << count << " small word(s)." << std::endl;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::vector<std::string> container;
    std::istringstream ist(line);
    std::string val;
    while (ist >> val)
        container.push_back(val);
    
    int thresh;
    std::cin >> thresh;
    smallies(container, thresh);

    return 0;
}
