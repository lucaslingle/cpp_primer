/*
Using Table 4.12 (p. 166) parenthesize the following expressions 
to indicate the order in which operands are grouped.

(a) * vec.begin()
(b) * vec.begin() + 1
*/

// table 4.12 puts member selectors two levels of precedence above dereferencing. 
// and dereferencing is three levels of precedence above addition and subtraction.
//
// (a) (*(vec.begin()))
// (b) ((*(vec.begin()))+1)
