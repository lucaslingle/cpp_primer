/*
Would it be possible to define isShorter as a constexpr? 
If so do so, if not explain why not.
*/

// I thought the answer was yes, but apparently strings are not "constexpr friendly", 
// because they allocate dynamic memory, which was not supported at compile time until C++20.
constexpr bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
