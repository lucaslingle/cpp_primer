/*
Write a program that uses a do while loop to repetitively request two strings from the user,
and report which string is less than the other.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    do {
        string s1, s2;
        cin >> s1 >> s2;
        cout << ((s1 < s2) ? "s1 < s2" : "s1 >= s2") << endl;
    } while (cin);
    return 0;
}
