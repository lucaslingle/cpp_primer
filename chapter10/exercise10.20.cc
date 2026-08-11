/*
The library defines an algorithm named ```count_if```. Like ```find_if```, 
this function takes a pair of iterators denoting an input range and a predicate
that it applies to each element in the given range. ```count_if``` returns a count
of how often the predicate is true. Use ```count_if``` to rewrite the portion of
our program that counted how many words are greater than length 6. 
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
    // sort alphabetically
    std::sort(words.begin(), words.end());
    // move duplicates to the end
    auto end_unique = std::unique(words.begin(), words.end());
    // erase duplicates
    words.erase(end_unique, words.end());
    // print number of big words
    int count = std::count_if(words.begin(), words.end(), 
                              [sz](const std::string &s) 
                              { return s.size() >= sz; });
    std::cout << "got " << count << " long word(s)." << std::endl;
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
