/*
Write your own version of a simple desk calculator 
that can handle binary operations. 
*/

#include <iostream>
#include <functional>
#include <map>

int main() {
    std::map<char, std::function<int(int, int)>> lookup;
    lookup.insert({'+', std::plus<int>()});
    lookup.insert({'-', std::minus<int>()});
    lookup.insert({'*', std::multiplies<int>()});
    lookup.insert({'/', std::divides<int>()});

    int lhs, rhs;
    char op;

    std::cin >> lhs;
    while (std::cin >> op) {
        std::cin >> rhs;
        lhs = lookup[op](lhs, rhs);
        std::cout << "got: " << lhs << std::endl;
    }

    return 0;
}