/*
Use an explicit template argument to make it sensible to pass two
string literals to the original version of `compare` from p. 652.

reference code:
```
template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```
*/

// An explicit template argument of std::string in place of T
// would allow the normal implicit conversion rules to apply,
// and in particular would allow std::string's conversion constructor
// to be applied to both arguments.
