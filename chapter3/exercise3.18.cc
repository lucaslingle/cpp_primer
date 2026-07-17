/*
Is the following program legal? If not, how might you fix it?
```
vector<int> ivec;
ivec[0] = 42;
```
*/

// ivec has length zero, so the index is out-of-bounds 
// and yields undefined behavior. to fix it, write
// ivec.push_back(42);
// this will add it to the 'end' of the vector, 
// which for a length zero vector is also the beginning. 
