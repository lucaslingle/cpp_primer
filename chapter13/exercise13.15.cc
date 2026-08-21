/*
Assume ```Numbered``` from the previous exercise has a copy constructor
that generates a new serial number. Does that change the output of the calls
in the previous exercise? If so, why? What output gets generated?
*/

// the variables b and c are copy-initialized, so having a copy
// constructor that generates a new serial number changes the output
// so that all three calls to f print the serial numbers of the copies
// of a, b, and c internal to f.
