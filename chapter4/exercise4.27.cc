/*
What is the result of each of these expressions?

unsigned long ull = 3, ul2 = 7;
(a) ul1 & ul2;
(b) ul1 | ul2;
(c) ul1 && ul2;
(d) ul1 || ul2;
*/

// (a) ul1 = [24 or more zeros][00000011], 
//     ul2 = [24 or more zeros][00000111].
// ul1 & ul2 is [24 or more zeros][00000111] = 7.

// (b) ul1 | ul2 is [24 or more zeros][00000011] = 3.

// (c) ul1 and ul2 are both nonzero and are converted to boolean true by the logical AND operator.
// the result is boolean true.

// (c) ul1 and ul2 are both nonzero and are converted to boolean true by the logical OR operator.
// the result is boolean true.
