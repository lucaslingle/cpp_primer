/*
Explain each of the following definitions. 
Indicate whether any are illegal and, if so, why. 


int i = 0;

(a) double *dp = &i;
(b) int *ip = i;
(c) int *p = &i; 
*/

// (a) invalid. &i is the address of an int,
//     and it gives an error to store in a pointer to a double. 
// (b) invalid. i is an integer variable and cannot be assigned to a pointer. 
// (c) valid. 