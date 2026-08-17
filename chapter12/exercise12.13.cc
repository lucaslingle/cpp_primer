/*
What happens if we execute the following code?
```
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```
*/

// the object pointed to by p and sp will be deleted.
// p and sp will be dangling pointers.
// the stored reference count of sp will still be 1.
// if the count drops to zero before the program exits, 
// a double free of heap memory will occur, resulting in undefined behavior.
