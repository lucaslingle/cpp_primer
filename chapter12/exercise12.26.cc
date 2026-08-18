/*
Rewrite the program on p. 481 using an allocator.

reference code:
```
string *const p = new string[n];
string s;
string *q = p;
while (cin >> s && q != p + n)
    *q++ = s;
const size_t size = q - p;
delete[] p;
```
*/

#include <iostream>
#include <string>
#include <memory>
using std::cin;
using std::string;
using std::allocator;

int main() {
    int n = 10;  // or whatever

    allocator<string> alloc;
    auto p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
        alloc.construct(q++, s);

    while (q != p)
        alloc.destroy(--q);  
    // note: alloc.destroy deprecated in C++17, rm'd in C++20
    // modern alternative to loop and alloc.destroy is std::destroy(p, q);
    alloc.deallocate(p, n);
}
