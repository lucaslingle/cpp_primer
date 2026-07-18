/*
Rewrite the programs from the previous exercise 
using a type alias for the type of the loop control variables.
*/

#include <iostream>
#include <iterator>

using Row = int[4];
using RowIdx = int;
using RowPtr = int(*)[4];

using Col = int;
using ColIdx = int;
using ColPtr = int*;

int main() {
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    std::cout << "____" << std::endl;
    for (Row &row : ia) {
        for (Col col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }

    std::cout << "____" << std::endl;
    for (RowIdx row_idx = 0; row_idx != 3; ++row_idx) {
        for (ColIdx col_idx = 0; col_idx != 4; ++col_idx)
            std::cout << ia[row_idx][col_idx] << " ";
        std::cout << std::endl;
    }

    std::cout << "____" << std::endl;
    for (RowPtr p = std::begin(ia); p != std::end(ia); ++p) {
        for (ColPtr q = std::begin(*p); q != std::end(*p); ++q)
            std::cout << *q << " ";
        std::cout << std::endl;
    }

    return 0;
}