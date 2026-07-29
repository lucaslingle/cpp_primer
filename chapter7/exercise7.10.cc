/*
What does the condition in the following if statement do?
```
if (read(read(cin, data), data2))
```
*/

// the inner read uses the stream cin to modify data1.
// the outer read uses the returned stream cin from the first read call to modify data2.
