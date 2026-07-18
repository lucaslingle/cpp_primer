/*
Write three different versions of a program to print the elements of ia.
One version should use a range for to manage the iteration,
the other two should use an ordinary for loop in one case using subscripts,
and in the other case using pointers.

In all three programs, write all the types directly. That is, do not use a 
type alias, auto, or decltype to simplify the code.
*/

#include <iostream>
#include <iterator>

int main() {
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    std::cout << "____" << std::endl;
    for (int (&row)[4] : ia) {
        for (int col : row)
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
    for (int (*p)[4] = std::begin(ia); p != std::end(ia); ++p) {
        for (int *q = std::begin(*p); q != std::end(*p); ++q)
            std::cout << *q << " ";
        std::cout << std::endl;
    }

    return 0;
}