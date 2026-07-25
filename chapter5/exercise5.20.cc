/*
Write a program to read a sequence of strings from the standard input
until either the same word occurs twice in succession or all words have been read.
Use a while loop to read the text one word at a time. Use the break statement
to terminate the loop if a word occurs twice in succession. Print the word if it 
occurs twice in succession, or else print a message saying no word was repeated.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string word, prevword;
    while (cin >> word) {
        if (word == prevword)
            break;
        prevword = word;
    }
    if (word == prevword)
        cout << "first word occurring twice in succession: " << word << endl;
    else
        cout << "no word occurred twice in succession." << endl;
    return 0;
}
