/*
Write a program that defines a multimap of autors and their works.
Use find to find an element in multimap and erase that element.
Be sure your program works correctly if the element you look for is not in the map.
*/

#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::multimap;

int main() {
    multimap<string, string> author2titles;
    author2titles.insert({"J. R. R. Tolkien", "The Hobbit"});
    author2titles.insert({"J. R. R. Tolkien", "The Fellowship of the Ring"});
    author2titles.insert({"William Gibson", "Neuromancer"});

    // find one of multiple titles for author
    auto it = author2titles.find("J. R. R. Tolkien");
    if (it != author2titles.end())
        author2titles.erase(it);

    // missing from above
    auto it2 = author2titles.find("J. K. Rowling");
    if (it2 != author2titles.end())
        author2titles.erase(it);

    for (auto kv : author2titles)
        cout << kv.first << ": " << kv.second << endl;
    return 0;
}
