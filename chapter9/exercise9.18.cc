/*
Write a program to read a sequence of strings from the standard input
into a deque. Use iterators to write a loop to print the elements in the deque.
*/

#include <iostream>
#include <string>
#include <deque>

int main() {
    std::string word;
    std::deque<std::string> dq;
    while (std::cin >> word)
        dq.push_back(word);

    for (auto beg = dq.cbegin(); beg != dq.cend(); ++beg)
        std::cout << *beg << " ";
    std::cout << std::endl;
    return 0;
}
