/*
Explain how the loop from p. 345 that used the return from insert
to add elements to a list would work if we used a vector instead.

reference code:
```
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
    iter = lst.insert(iter, word);
```
*/

// the code on p. 345 uses an iterator set to the head of a list 
// to initialize the process. a vector would also support the same operations,
// and would allow us to prepend without using a push_forward method 
// (which vector lacks).
//
// however, since vectors are designed differently, internal data copying would 
// occur on each call to insert. 
