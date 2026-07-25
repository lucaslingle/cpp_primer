/*
The while loop is particularly good at executing while some condition holds;
for example, when we need to read values until end-of-file. The for loop is
generally thought of as a step loop: an index steps through a range of values
in a collection. Write an ideomatic use of each loop and then rewrite each
using the other loop construct. 

If you could only use one loop, which would you choose? Why?
*/

// i would choose for loops because they include initializer, condition, expression
// and not just condition. the initializer and expression can be dropped flexibly.
#include <iostream>
#include <string>

void ideomatic_while() {
    string word;
    while (std::cin >> word && word.size() > 10)
        ;
}

void ideomatic_for() {
    std::vector<int> vec = {0, 1, 2}
    for (int i = 0; i != 3; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void nonideomatic_for() {
    string word;
    for (; std::cin >> word && word.size() > 10; )
        ;
}

void nonideomatic_while() {
    std::vector<int> vec = {0, 1, 2}
    int i = 0;
    while (i != 3) {
        std::cout << vec[i] << " ";
        ++i;
    }
    std::cout << std::endl;
}
