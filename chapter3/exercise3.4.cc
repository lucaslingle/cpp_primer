/*
Write a program to read two strings and report whether the strings are equal.
If not, report which of the two is larger. 

Now, change the program to report whether the strings have the same length, 
and if not report which is longer. 
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int content_ordering(string s, string t) {
    if (s < t)
        return -1;
    else if (s > t) 
        return 1;
    return 0;
}

int length_ordering(string s, string t) {
    auto sl = s.size();
    auto tl = t.size();
    if (sl < tl)
        return -1;
    else if (sl > tl) 
        return 1;
    return 0;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << content_ordering(s, t) << endl;
    cout << length_ordering(s, t) << endl;
    return 0;
}
