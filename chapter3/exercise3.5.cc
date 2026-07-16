/*
Write a program to read strings from standard input, concatenating
what is read into one large string. Print the concatenated string.

Next, change the program to separate the adjacent input strings by a space.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main() {
    string cat_nospace, cat_yesspace, line;
    bool first = true;
    while (getline(cin, line)) {
        cat_nospace += line;
        if (first)
            cat_yesspace += line;
        else
            cat_yesspace += " " + line;
        first = false;
    }
    cout << cat_nospace << endl;
    cout << cat_yesspace << endl;
    return 0;
}
