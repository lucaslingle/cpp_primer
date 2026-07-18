/*
Identify the indexing errors in the following code:
```
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
```
*/

// the valid array indices range from 0 to array_size-1, inclusive.
// this means the array access on ix = 10 above is invalid.
