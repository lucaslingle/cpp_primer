/*
Write a function to determine whether a string contains any capital letters.
Write a function to change a string to all lowercase.
Do the parameters you used in these functions have the same type? Why or why not?
*/

#include <cctype>

using std::toupper;
using std::tolower;

bool any_uppercase(const string &s) {
    for (auto c : s)
        if (c == toupper(c))
            return true;
    return false;
}

void to_lowercase(string &s) {
    for (auto &c : s)
        c = tolower(c);
}

// first func uses ref because why copy a large string, 
// and it uses const because we are not modifying string.
// const& allows const strings, literals, and objects requiring conversion
// to be passed to the function, making it more useful.

// second func uses ref because we're modifying the string.
// it does not use const because the string is being modified in-place.
