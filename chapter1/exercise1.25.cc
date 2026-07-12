/*
Using the Sales_item.h header from the website, compile and execute the
bookstore program presented in this section.
*/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

// output example:
// $ clang++ -std=c++11 -stdlib=libc++ exercise1.25.cc
// $ ./a.out <exercise1.24.txt  
// 0-201-78345-X 5 110 22
// 1-201-78345-X 3 63 21
// 2-201-78345-X 8 173 21.625
