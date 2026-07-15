/*
Is the following code legal or not? If not how might you make it legal?
```
int null = 0, *p = null;
```
*/

// code equiv to 
// int null = 0;
// int *p = null;
//
// the code is invalid because a pointer cannot be initialized using an int variable,
// only a nullptr object, an int literal 0, an address can be used to initialize a pointer.
