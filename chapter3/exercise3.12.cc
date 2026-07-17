/*
Which if any of the following vector definitions are in error?
For those that are legal explain what the definition does.
For those that are not legal, explain why they are illegal.

(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");
*/

// (a) valid. a vector of vector of ints, with default initialization (no elements).
// (b) invalid. a vector of strings whose copy initialization assigns from a vector of ints. 
// (c) valid. a vector of strings initialized from an element count (10) and value (the string "null"). 