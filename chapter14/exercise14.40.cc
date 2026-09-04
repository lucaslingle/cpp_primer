/*
Rewrite the `biggies` function from p. 391 (exercise 10.16) 
to use function-object classes in place of lambdas.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

class StringShorter {
    public:
        bool operator()(const std::string &s1, const std::string &s2) const {
            return s1.size() < s2.size();
        }
};

class StringMeasurer {
    public:
        StringMeasurer(std::size_t n): sz(n) { }
        bool operator()(const std::string &s) const { 
            return s.size() >= sz; 
        }
    private:
        std::size_t sz;
};

class StringPrinter {
    public:
        StringPrinter(std::ostream& ost, char sep): ost(ost), sep(sep) { }
        std::ostream& operator()(const std::string &s) const {
            ost << s << sep;
            return ost;
        }
    private:
        std::ostream& ost;
        char sep;
};

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
    // sort alphabetically
    std::sort(words.begin(), words.end());
    // move duplicates to the end
    auto end_unique = std::unique(words.begin(), words.end());
    // erase duplicates
    words.erase(end_unique, words.end());
    // sort words by size while maintaining alphabetical sort order per size
    std::stable_sort(words.begin(), words.end(), StringShorter());
    // find big words
    auto big_start = std::find_if(words.begin(), words.end(), StringMeasurer(sz));
    // print number of big words
    auto count = words.end() - big_start;
    std::cout << "got " << count << " big word(s)." << std::endl;
    // print the big words
    for_each(big_start, words.end(), StringPrinter(std::cout, ' '));
    std::cout << std::endl;
}

int main() {
    std::cout << "type in a line containing some words:" << std::endl;
    std::string line;
    std::getline(std::cin, line);

    std::vector<std::string> container;
    std::istringstream ist(line);
    std::string val;
    while (ist >> val)
        container.push_back(val);
    
    std::cout << "type in a line containing an integer:" << std::endl;
    std::size_t thresh;
    std::cin >> thresh;
    biggies(container, thresh);

    return 0;
}
