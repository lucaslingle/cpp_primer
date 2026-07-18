/*
What does the following program do?
```
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```
*/

// it keeps iterating through memory until it gets a null byte.
// there is no null byte guaranteed to be at the location immediately 
// following the end of the array, or anywhere else.
