/*
Reimplement the program that eliminated duplicate words that we
wrote in Sec 10.2.3 (p. 383) to use a list instead of a vector. 

reference code:
```
void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
```
*/

#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::list;

void elimDups(list<string> &words) {
    words.sort();
    words.unique();
}

int main() {
    list<string> ls = {"hello", "hello", "world", "hello", "hi"};
    elimDups(ls);

    for (const auto &s : ls)
        cout << s << " ";
    cout << endl;
    
    return 0;
}