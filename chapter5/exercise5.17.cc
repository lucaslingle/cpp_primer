/*
Given two vectors of ints, write a program to determine whether one vector
is a prefix of the other. For vectors of unequal length, compare the number
of elements of the smaller vector. For example given {0, 1, 1, 2} and 
{0, 1, 1, 2, 3, 5, 8}, your program should return true.
*/

#include <iostream>
#include <vector>

bool vecprefix(std::vector<int> v1, std::vector<int> v2) {
    decltype(v1)::size_type halt = (v1.size() < v2.size()) ? v1.size() : v2.size();
    for (decltype(v1)::size_type i = 0, j = 0; i != halt && j != halt; i++, j++)
        if (v1[i] != v2[i])
            return false;
    return true;
}
