/*
In the exercises for sec 10.3.2 (p. 392) you wrote a version of ```biggies``` that 
uses ```partition```. Rewrite that function to use check_size and bind.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() >= sz;
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
    // sort alphabetically
    std::sort(words.begin(), words.end());
    // move duplicates to the end
    auto end_unique = std::unique(words.begin(), words.end());
    // erase duplicates
    words.erase(end_unique, words.end());

    // move big words to the front
    auto big_end = std::stable_partition(words.begin(), words.end(), 
                                         std::bind(check_size, _1, sz));

    // print number of big words
    auto count = big_end - words.begin();
    std::cout << "got " << count << " big word(s)." << std::endl;
    // print the big words
    for_each(words.begin(), big_end, 
             [](const std::string &s) 
             { std::cout << s << " "; });
    std::cout << std::endl;
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
    biggies(container, thresh);

    return 0;
}
