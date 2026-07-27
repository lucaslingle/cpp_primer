/*
The following function, although legal, is less useful than it might be.
Identify and correct the limitation on this function:
```
bool is_empty(string &s) {
    return s.empty();
}
```
*/

// is_empty cannot be called on const objects, literals, or objects that
// require conversion to typpe string (example: C-style strings). 
//
// fix is to use const string& type:

bool is_empty(const string &s) {
    return s.empty();
}
