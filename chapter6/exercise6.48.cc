/*
Explain what this loop does and whether it is a good use of assert.
```
string s;
while (cin >> s && s != sought) { }  // empty body
assert(cin);
```
*/

// the program loops and looks for the variable sought.
// when it stops, either cin is evaluates to false or s == sought.
// using assert is a rudimentary and ill-advised way to check which.
//
// the assert will be ignored if NDEBUG is passed and 
// perhaps also should not be used because cin evaluating to false 
// is a perfectly reasonable thing to happen for some input streams. 
