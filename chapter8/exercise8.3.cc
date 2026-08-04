/*
What causes the following while to terminate?
```
while (cin >> i) { ... }
```
*/

// if cin encounters an error during reading, 
//     badbit and failbit will be set and the while will terminate.
// if cin encounters a string that cannot be cast to an int (assuming i is int), 
//     failbit will be set and the while will terminate.
// if cin encounters an end-of-file during reading,
//     eofbit and failbit will be set and the while will terminate. 
