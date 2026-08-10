/*
Write a program that uses stable_sort and isShorter to sort a vector
passed to your version of elimDups. Print the vector to verify that
your program is correct.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_vec(std::ostream &outp, const std::vector<std::string> &vec) {
    for (const auto &i : vec)
        outp << i << " ";
    outp << std::endl;
}

void elim_dups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool is_shorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {
    std::string val;
    std::vector<std::string> container;
    while (std::cin >> val)
        container.push_back(val);
    elim_dups(container);
    std::stable_sort(container.begin(), container.end(), is_shorter);
    print_vec(std::cout, container);
    return 0;
}
