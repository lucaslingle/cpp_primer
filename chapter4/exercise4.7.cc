/*
What does overflow mean? Show three expressions that will overflow.
*/

// overflow means that an expression in infinite precision produces a value larger
// than can be stored in a variable of a given type.
// examples:

// char c = 255; c++;      // assumes 8-bit char
// short s = 32768; s++;   // assumes 16-bit short
// int i = 2147483647; i++ // assumes 32-bit int
