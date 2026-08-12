/*
Define a map that associates words with a list of line numbers
on which the word might occur.
*/

#include <iostream>
#include <map>
#include <list>
#include <string>

int main() {
    std::map<std::string, std::list<int>> word2lineno;
    word2lineno["hello"] = {1, 2, 3};
    word2lineno["world"] = {4, 5, 6};
    for (auto kv : word2lineno) {
        std::cout << kv.first << ": ";
        for (auto v : kv.second)
            std::cout << v << ", ";
        std::cout << std::endl;
    }
    return 0;
}
