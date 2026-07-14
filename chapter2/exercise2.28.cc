/*
Explain the following definitions. Identify any that are illegal.
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
*/

// (a) int i is valid. int *const cp is invalid because it is an uninitialized constant. 
//     int i defines an integer variable. 
//     int *const cp if initialized would define a constant pointer to an int. 
//
// (b) int *p1 is valid. int *const p2 is invalid because it is an uninitialized constant. 
//     int *p1 defines a pointer to an integer. 
//     int *const p2 if initialized would define a constant pointer to an int. 
//
// (c) const int ic is invalid because it is an uninitialized constant. 
//     const int &r = ic is valid if if ic is initialized, and invalid otherwise. 
//     const int ic defines a constant integer variable.
//     const int &r = ic defines a constant integer reference variable.
//
// (d) const int *const p3 is because it is an uninitialized constant. 
//     if initialized, it would be a constant pointer to a constant int object. 
//
// (e) const int *p is valid. it is an uninitialized pointer to a constant int. 