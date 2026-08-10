/*
Rewrite the previous exercise to use stable_partition, which like stable sort
maintains the original element order (in the partitions of the sequence).
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

    // // sort words by size while maintaining alphabetical sort order per size
    // std::stable_sort(words.begin(), words.end(), 
    //                  [](const std::string &s1, const std::string &s2) 
    //                  { return s1.size() < s2.size(); });
    // // find big words
    // auto big_start = std::find_if(words.begin(), words.end(), 
    //                               [sz](const std::string &s) 
    //                               { return s.size() >= sz; });

    // // move big words to the front
    // auto big_end = std::partition(words.begin(), words.end(), 
    //                [sz](const std::string &s) 
    //                { return s.size() >= sz; });

    // move big words to the front
    // stable partition will maintain alphabetical order 
    // (but not relative word-size order since we commented stable_sort out)
    auto big_end = std::stable_partition(words.begin(), words.end(), 
                                         [sz](const std::string &s) 
                                         { return s.size() >= sz; });

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
