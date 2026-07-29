/*
Give the third parameter to ```make_plural``` (p 224) a default argument of 's'.
Test your program by printing singular and plural versions of the words 
```success`` and ```failure```.
*/

#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::string;
using std::size_t;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    string s1 = "success";
    string s2 = "failure";

    cout << make_plural(1, s1) << endl;
    cout << make_plural(2, s1) << endl;

    cout << make_plural(1, s2) << endl;
    cout << make_plural(2, s2) << endl;

    return 0;
}
