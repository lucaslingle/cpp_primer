/*
Explain the effect of the second declaration in each of the following
sets of declarations. Indicate which, if any, are illegal.

(a) 
```
int calc(int, int);
int calc(const int, const int);
```

(b)
```
int get();
double get();
```

(c)
```
int *reset(int *);
double *reset(double *);
```
*/

// (a) top-level const is ignored here, so second def is illegal duplicate.
// (b) parameter lists are identical, so second def is illegal duplicate.
// (c) both functions have different parameter types, so both are legal.
