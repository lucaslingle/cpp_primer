/*
Which if any of the following calls are illegal? Why?
Which if any are legal but unlikely to match the programmer's intent? Why?

char *init(ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24, 10);
(c) init(14, '*');
*/

// (a) is illegal because it omits an argument for param ht, which has no default.
// (b) is legal, and calls init(24, 10, ' ');
// (c) is legal, but calls init(14, '*', ' '); the char '*' is converted to int.
