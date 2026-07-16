/*
Rewrite the program in exercise 3.6 first using a while 
and again using a traditional for loop.
Which of the three approaches do you prefer?
*/

// range-based for loop seems cleanest in terms of syntax.
#include <iostream>
#include <string>

int forrange_func() {
    std::string s;
    std::getline(std::cin, s);
    for (auto &c : s)
        c = 'X';
    std::cout << s << std::endl;
}

int while_func() {
    std::string s;
    std::getline(std::cin, s);
    decltype(s.size()) i = 0;
    while (i < s.size()) {
        s[i] = 'X';
        ++i;
    }
    std::cout << s << std::endl;
}

int fori_func() {
    std::string s;
    std::getline(std::cin, s);
    for (decltype(s.size()) i = 0; i < s.size(); ++i)
        s[i] = 'X';
    std::cout << s << std::endl;
}
