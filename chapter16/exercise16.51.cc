/*
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

// 3,3
// 2,2
// 1,1
// 0,0
