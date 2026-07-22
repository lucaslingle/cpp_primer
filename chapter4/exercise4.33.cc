/*
Using Table 4.12 (p. 166) explain what the following expression does:
someValue ? ++x, ++y : --x, --y
*/

// based on whether someValue is true, it either increments x and y or decrements x and y.
// in either case, the result of a comma expression is the value of its right-hand expression,
// i.e. the new value of y.
