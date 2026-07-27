/*
Write declarations for each of the following functions.
When you write these declarations, use the name of the function to 
indicate what the function does.

(a) a function named ```compare``` that returns bool and has two parameters
that are references to a class named matrix.

(b) a function named ```change_val``` that returns a vector<int> iterator
and takes two parameters: one is an int and the other is a vector<int> iterator.
*/

#include <vector>
using std::vector;

bool compare(matrix &m1, matrix &m2);
vector<int>::iterator change_val(int n, vector<int>::iterator it);
