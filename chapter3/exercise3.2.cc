/*
Write a program to read the standard input a line at a time.
Modify your program to read a word at a time.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

void read_lines() {
    string line;
    while (getline(cin, line))
        cout << line << endl;
}

void read_words() {
    string word;
    while (cin >> word)
        cout << word << endl;
}

int main() {
    // read_lines();
    read_words();
    return 0;
}
