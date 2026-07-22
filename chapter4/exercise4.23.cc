/*
The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166) explain why it fails. How would you fix it?
```
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```
*/

// the user's intended precedence is s + ((s[s.size() - 1] == 's') ? "" : "s"),
// but using table 4.12, + is highest, then ==, then ?:.
// so we have ((s + s[s.size() - 1]) == 's') ? "" : "s"), 
// which is invalid because it compares a string to a char. 

#include <string>
using std::string;

int main() {
    string s = "word";
    // string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");
    // string pl = ((s + s[s.size() - 1]) == 's') ? "" : "s";
    string pl = s + s[s.size() - 1] == 's' ? "" : "s";
    return 0;
}
