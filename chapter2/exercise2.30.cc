/*
For each of the following declarations indicate 
whether the object being declared has top-level or low-level const. 
*/

// const int v2 = 0; // top-level
// int v1 = v2;      // neither, src top-lvl const ignored on copy. 
// int *p1 = &v1;    // neither
// int &r1 = v1;     // neither
// const int *p2 = &v2;      // low-level
// const int *const p3 = &i  // both
// const int &r2 = v2;       // low-level
