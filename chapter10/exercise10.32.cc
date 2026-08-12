/*
Rewrite the bookstore program from exercise 1.25 using a vector to 
hold the transactions and various algorithms to do the processing.
Use sort with your compareIsbn function from p. 387 to arange the transactions
in order, and then use find and accumulate to do the sum.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include "Sales_item.h"
using namespace std::placeholders;

bool compare_isbn(const Sales_item &d1, const Sales_item &d2) {
    return d1.isbn() < d2.isbn();
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw std::runtime_error("bad format. expected: prog.o input_fname");

    std::vector<Sales_item> vec;
    std::ifstream inp(argv[1]);
    Sales_item item;
    while (inp >> item)
        vec.push_back(item);
    std::sort(vec.begin(), vec.end(), compare_isbn);

    std::vector<Sales_item> totals;
    auto it = vec.cbegin();
    while (it != vec.cend()) {
        auto end = std::find_if(it, vec.cend(), std::bind(compare_isbn, *it, _1));
        if (it < end) {
            Sales_item initial = *it;
            Sales_item sum = std::accumulate(++it, end, initial);
            totals.push_back(sum);
        }
        it = end;
    }
    
    std::ostream_iterator<Sales_item> output_iter(std::cout, "\n");
    std::copy(totals.begin(), totals.end(), output_iter);
    std::cout << std::endl;
    return 0;
}
