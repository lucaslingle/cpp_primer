/*
Which, if any of the following assignments are invalid?
If they are valid, explain what they do.

int i = 0, &r1 = i;
double d = 0, &r2 = d;

(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
*/

// (a) valid. assigns 3.14159 from double literal to the double d (referenced by r2).
//
// (b) valid. assigns value 0 from i object (referenced by r1) to the double d (referenced by r2). 
//
// (c) valid. assigns value 0.0 from d object (referenced by r2) to the int i (after truncation).
//
// (d) valid. assigns value 0.0 from d object to the int i (referenced by r1) (after truncation).


// code to verify the answers.
#include <iostream>

int main() {
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    // comment-in exactly one in at a time.

    // r2 = 3.14159;
    // std::cout << d << std::endl;

    // r2 = r1;
    // std::cout << d << std::endl;

    // i = r2;
    // std::cout << i << std::endl;

    // r1 = d;
    // std::cout << i << std::endl;
}
