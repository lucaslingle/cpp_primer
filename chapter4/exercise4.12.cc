/*
Assuming i, j, k are all ints explain what i != j < k means.
*/

// the order of precedence is logical not, followed by relational,
// followed by equality/inequality, followed by logical AND, followed by logical OR.
// thus,
// we have (i != j < k) == (i != (j < k)),
// so if (j < k) then the resulting bool is converted to int 1, 
// and otherwise then the resulting bool is converted to int 0,
// and i is compared to that value.
