/*
Given the following declarations
```
void manip(int, int);
double dobj;
```
what is the rank (p. 245) of each conversion in the following calls?
(a) manip('a', 'z');
(b) manip(55.4, dobj);
*/

// the ranking order is:
// 1. exact match, pointer decay match, or top-level const conversion.
// 2. const conversion.
// 3. integral promotion.
// 4. general arithmetic conversion or pointer conversion.
// 5. class conversion.

// (a) char is an integral type. for manip(int, int), 'a' and 'z' arguments 
// are both promoted to int type, so the rank is 3.

// (b) 55.4 is a double literal, and dobj is a double variable. 
// for manip(int, int), both are converted to int via truncation, 
// which is a general arithmetic conversion, so the rank for both arguments is 4.
