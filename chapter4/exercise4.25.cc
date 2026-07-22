/*
What is the value of ~'q' << 6 on a machine with 32-bit ints and 8-bit chars,
that uses the Latin-1 character set in which 'q' has the bit pattern 01110001?
*/

// unsigned char q has bit pattern 01110001, 
// and is promoted to a 32-bit int when bitwise negated.  
// we have ~(00000000 00000000 00000000 01110001)
//   equals  11111111 11111111 11111111 10001110
// followed by left shift by six places:
//   equals  11111111 11111111 11100011 10000000
//
// assuming a twos complement machine this is
// "negative" of 00000000 00000000 00011100 01111111
// adding one we have
// "negative" of 00000000 00000000 00011100 10000000
//
// or -7296 in decimal.
