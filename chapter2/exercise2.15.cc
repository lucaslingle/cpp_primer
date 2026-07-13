/*
Which of the following definitions, if any, are invalid? Why?

(a) int ival = 1.01;
(b) int &rval = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
*/

// (a) is valid, but assigns a truncated value 1 to ival.
// (b) is invalid, both because it tries to reference a literal instead of an object,
//     and because the literal is of the wrong type.
// (c) is valid, because ival is an object of the correct type: an int.
// (d) is invalid, because a reference cannot be rebound, it must be initialized.
