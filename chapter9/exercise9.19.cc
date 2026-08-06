/*
Rewrite the program from the previous exercise to use a list.
List the changes you needed to make.
*/

#include <iostream>
#include <string>
#include <list> // change from deque

int main() {
    std::string word;
    std::list<std::string> dq;  // change from deque
    while (std::cin >> word)
        dq.push_back(word);

    for (auto beg = dq.cbegin(); beg != dq.cend(); ++beg)
        std::cout << *beg << " ";
    std::cout << std::endl;
    return 0;
}
