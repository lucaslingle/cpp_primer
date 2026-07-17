/*
Rewrite the grade clustering program from Sec 3.3.3 
using iterators instead of subscripts. 
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade)
        if (grade <= 100)
            *(scores.begin() + grade/10) += 1;

    std::cout << "{ ";
    for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
        std::cout << *it;
        std::cout << ", ";
    }
    std::cout << "}";
    std::cout << std::endl;
    
    return 0;
}
