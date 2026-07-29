/*
Which, if either, of the following declarations are errors? Why?
(a) int ff(int a, int b = 0, int c = 0);
char *init(int ht = 24, int wd, char bckgrnd);
*/

// (a) is ok because it uses default arguments only for a tail of the param list.
// (b) is an error because it supplies default arguments for one param,
//     followed by no default arguments for the subsequent one(s).
