/*
Revise the loop that printed the first paragraph in text to instead change 
the elements in text that correspond to the first paragraph to all uppercase.
After you've updated text, print its contents.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::toupper;

int main() {
    vector<string> text = {
        "The quick brown fox jumps.", 
        "", 
        "He jumps over the lazy dog."
    };

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        for (auto &c : *it)
            c = toupper(c);

    for (auto it = text.cbegin(); it != text.cend(); ++it)
        cout << *it << endl;
    return 0;
}
