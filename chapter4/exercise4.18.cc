/*
What would happen if the while loop on p. 148 that prints 
elements from a vector used the prefix increment operator?
```
auto pbeg = v.begin();
while (pbeg != v.end() && *pbeg >= 0)
    cout << *pbeg++ << endl;
```
*/

// the code would skip the first element of v,
// and if all of the elements of v are nonnegative,
// it would also dereference one element past the end of v,
// resulting in undefined behavior. 