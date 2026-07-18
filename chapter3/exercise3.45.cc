/*
Rewrite the previous exercise solution, this time using auto.
*/

#include <iostream>
#include <iterator>

int main() {
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    std::cout << "____" << std::endl;
    for (auto &row : ia) {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }

    std::cout << "____" << std::endl;
    for (int row_idx = 0; row_idx != 3; ++row_idx) {
        for (int col_idx = 0; col_idx != 4; ++col_idx)
            std::cout << ia[row_idx][col_idx] << " ";
        std::cout << std::endl;
    }

    std::cout << "____" << std::endl;
    for (auto p = std::begin(ia); p != std::end(ia); ++p) {
        for (auto q = std::begin(*p); q != std::end(*p); ++q)
            std::cout << *q << " ";
        std::cout << std::endl;
    }

    return 0;
}