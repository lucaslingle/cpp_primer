/*
Should the class you chose for exercise 7.40 define the relational operators?
If so, implement them. If not, why not?
*/

// it is not obvious how to do < on trees.
// one way would be to treat them as intervals of values,
// so that the smallest and largest define a range,
// and if one range's max is less than the other's min, then < holds.
// this would be a partial ordering over trees.

// however, the main text says we should define a relation consistent with ==,
// so that if two objects are != then one object would be < the other.

// a partial ordering does not have this property.
// in particular, two distinct but overlapping tree ranges would be !=
// but neither would be < the other.
