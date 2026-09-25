/*
Write a program to check your answer to the previous question.

previous question:
Determine what `sizeof...(Args)` and `sizeof...(rest)` return
for each call to `foo` in this section.

reference code:
```
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);

int i = 0; double d = 3.14; string s = "how now brown cow";
foo(i, s, 42, d);
foo(s, 42, "hi");
foo(d, s);
foo("hi");
```
*/

// my given answers to the prev problem:
// 3,3
// 2,2
// 1,1
// 0,0

#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

int main() {
    int i = 0; double d = 3.14; std::string s = "how now brown cow";
    std::cout << "foo(i, s, 42, d);" << std::endl;
    foo(i, s, 42, d);

    std::cout << "foo(s, 42, \"hi\");" << std::endl;
    foo(s, 42, "hi");

    std::cout << "foo(d, s);" << std::endl;
    foo(d, s);

    std::cout << "foo(\"hi\");" << std::endl;
    foo("hi");
}
