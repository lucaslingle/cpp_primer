/*
Explain the effect of the second declaration in each of the following.
Indicate which if any are illegal.

(a)
```
int calc(int&, int&);
int calc(const int&, const int&);
```

(b)
```
int calc(char*, char*);
int calc(const char*, const char*);
```

(c)
```
int calc(char*, char*);
int calc(char* const, char* const);
```
*/

// (a) both are valid declarations; the second is distinct from the first
// because const references have a low-level const which is not ignored.

// (b) both are valid declarations; the second is distinct from the first
// because pointer to const has a low-level const which is not ignored.

// (c) the second declaration is a redeclaration; it uses a constant pointer,
// which has a top-level const that is ignored, so the second declaration 
// is a duplicate of the first. it is not illegal however.
