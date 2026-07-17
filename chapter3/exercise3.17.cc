/*
Read a sequence of words from cin and store the values in a vector.
After you've read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::toupper;

int main() {
    string word;
    vector<string> vec;
    while (cin >> word)
        vec.push_back(word);
    for (auto &s : vec)
        for (auto &c : s)
            c = toupper(c);
    for (decltype(vec)::size_type i = 0; i < vec.size(); ++i) {
        if (i > 0 && i % 8 == 0)
            cout << endl;
        cout << vec[i] + " ";
    }
    cout << endl;
}
