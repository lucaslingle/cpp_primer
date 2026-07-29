/*
Write a declaration for a function that takes two int parameters
and returns an int, and declare a vector whose elements have 
this function pointer type.
*/

#include <vector>

int func(int, int);
std::vector<decltype(func) *> vec;
std::vector<int(*)(int, int)> vec2;
