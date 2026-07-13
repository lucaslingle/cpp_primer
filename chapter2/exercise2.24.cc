/*
Why is the initialization of p legal but that of lp illegal?

int i = 42;
void *p = &i;
long *lp = &i;
*/

// void *p is a special type of pointer that CAN be used with addresses 
// for any type of variable. among pointer types, it has the unique properties 
// that it cannot be defererenced with *p nor elements accessed via p->element syntax. 
//
// long *lp cannot be used with an address for the int i, 
// because they have differing base types (long vs int). 
