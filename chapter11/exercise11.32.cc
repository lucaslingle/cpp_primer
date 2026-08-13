/*
Using the multimap from the previous exercise, 
write a program to print the list of authors and their works alphabetically.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
using std::cout;
using std::endl;
using std::string;
using std::multimap;
using std::set;

int main() {
    multimap<string, string> author2titles;
    author2titles.insert({"J. R. R. Tolkien", "The Hobbit"});
    author2titles.insert({"J. R. R. Tolkien", "The Fellowship of the Ring"});
    author2titles.insert({"J. R. R. Tolkien", "The Two Towers"});
    author2titles.insert({"J. R. R. Tolkien", "The Return of the King"});
    author2titles.insert({"William Gibson", "Neuromancer"});
    author2titles.insert({"William Gibson", "Count Zero"});
    author2titles.insert({"William Gibson", "Mona Lisa Overdrive"});
    author2titles.insert({"Andy Wier", "The Martian"});
    author2titles.insert({"Andy Wier", "Project Hail Mary"});
    // naive print gives titles in the insert order per key.

    set<string> authors;
    for (auto kv : author2titles)
        authors.insert(kv.first);

    for (auto author : authors) {
        set<string> titles;
        for (auto pair = author2titles.equal_range(author);
             pair.first != pair.second; 
             ++pair.first) {
            titles.insert(pair.first->second);
        }
        for (auto title : titles)
            cout << author << ": " << title << endl;
    }
    return 0;
}
