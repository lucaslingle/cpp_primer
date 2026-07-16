/*
What does the following program do? Is it valid? If not, why not?
```
string s;
cout << s[0] << endl;
```
*/

// the program is not valid because the default initialization 
// for a string is the empty string, so index 0 is out-of-bounds.
// out-of-bounds indices for strings yield undefined behavior.
