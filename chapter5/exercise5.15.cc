/*
Explain each of the following loops. Correct any problems you detect.

(a)
```
for (int ix = 0; ix != sz; ++ix) { ... }
if (ix != sz)
    ...
```

(b)
```
int ix;
for (ix != sz; ++ix) { ... }
```

(c)
```
for (int ix = 0; ix != sz; ++ix, ++ sz) { ... }
```
*/

// (a) the if condition uses ix and sz, but ix is local to the for loop.
// rewrite as:
//
// int ix = 0
// for (; ix != sz; ++ix) { ... }
// if (ix != sz)
// ...

// (b) the for loop requires a null statement in the initializer slot.
// rewrite as:
//
// int ix;
// for (; ix != sz; ++ix) { ... }

// (c) there is an extraneous space between ++ and sz. 
// rewrite as:
//
// for (int ix = 0; ix != sz; ++ix, ++sz) { ... }
//
// also, the loop header increments ix and sz until they reach the same value. 
// if neither variable is incremented inside the loop body, they will never be equal 
// unless initialized to the same value. 
