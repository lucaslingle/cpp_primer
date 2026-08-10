/*
Implement your own version of elimDups. Test your program by
printing the vector after you read the input, after the call to unique,
and after the call to erase.
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
    print_vec(std::cout, words);

    words.erase(end_unique, words.end());
    print_vec(std::cout, words);
}

int main() {
    std::string val;
    std::vector<std::string> container;
    while (std::cin >> val)
        container.push_back(val);
    print_vec(std::cout, container);

    elim_dups(container);
    return 0;
}
