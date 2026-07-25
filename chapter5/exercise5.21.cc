/*
Revise the program from exercise 5.20 so that it looks only for
duplicated words that start with an uppercase letter.
*/

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::isupper;

int main() {
    string word, prevword;
    while (cin >> word) {
        if (!isupper(word[0])) {
            prevword = "";
            continue;
        }
        if (word == prevword)
            break;
        prevword = word;
    }
    if (word == prevword)
        cout << "first uppercase word occurring twice in succession: " << word << endl;
    else
        cout << "no uppercase word occurred twice in succession." << endl;
    return 0;
}
