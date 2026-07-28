/*
Compile the version of str_subrange as presented on page 223
to see what your compiler does with the indicated errors.
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool str_subrange(const string &str1, const string &str2) {
    if (str1.size() == str2.size())
        return str1 == str2;  // ok: bool
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return;   // error no return value, compiler should detect. // it did!
    }
    // error no return statement, ctrl flow may reach, compiler may not detect.
    // update: it didn't!
}

int main() {
    string s1 = "Hello";
    string s2 = "Woooorld";
    cout << str_subrange(s1, s2) << endl;
    return 0;
}
