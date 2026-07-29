/*
Rewrite ```isShorter``` function from p 211 to be inline.
*/

#include <string>
using std::string;

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
