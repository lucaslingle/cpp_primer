/*
Explain the following loop.
```
constexpr int size = 5;
int ia[size] = {1, 2, 3, 4, 5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr)
    // ...
```
*/

// a temporary pointer variable ptr and a temporary index variable ix are initialized,
// to ia and to zero respectively. 
// while ix is not array length size and also the ptr is not off the end of the array,
// do the loop, and then increment ix and ptr.
 