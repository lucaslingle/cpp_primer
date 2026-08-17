/*
Explain what if anything is wrong with the following function.
```
bool b() {
   int* p = new int;
   // ...
   return p;
}
```
*/

// the return type is bool, so the returned pointer will be cast to false if nullptr,
// and true otherwise. consequently, there will be no proper way to call delete p,
// freeing the dynamically allocated memory. the result is a memory leak.

