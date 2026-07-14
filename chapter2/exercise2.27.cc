/*
Which of the following initializations are legal? Explain why.
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;
*/

// (a) int i = -1 is valid. int &r = 0 is invalid 
//     because an int literal cannot be used to initialize a reference. 
//
// (b) int *const p2 = &i2 is valid if i2 is an int. 
//     this pointer's stored address cannot change. 
//
// (c) const int i = -1 is valid. const int &r = 0 is invalid
//     because an int literal cannot be used to initialize a reference. 
//
// (d) const int *const p3 = &i2 is valid if i2 is an int. 
//     this pointer's stored address cannot change, 
//     and the pointed-to value cannot be modified via assignment 
//     to the dereferenced pointer. 
//
// (e) const int *p1 = &i2 is valid if i2 is an int. 
//     the pointed-to value cannot be modified via assignment 
//     to the dereferenced pointer. 
//
// (f) const int &const r2 is invalid and has no meaning. 
//     all references are already immutably bound to the target object. 
//     in addition, this reference is not initialized during its definition, 
//     which is invalid for a reference.
//
// (g) const int i2 = i is valid. const int &r = i is valid too. 
//     the reference r cannot be used to assign to i, because r has type [const int &].
//     the variable i cannot be assigned to directly, because it is has type [const int]. 
