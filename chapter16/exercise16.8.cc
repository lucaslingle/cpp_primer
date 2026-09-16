/*
In the "Key Concept" box on p. 108, we noted that as a matter of habit
C++ programmers prefer using != to <. Explain the rationale for this habit.
*/

// The remark on page 108 was specifically about iterators for STL containers, 
// not all of which define operator<. When writing templates that can handle 
// multiple STL container types, the for-loop condition specified with !=
// can be applied to STL container types whose iterators do not define <. 
//
// The same remark applies perhaps more broadly too: types such as pointers
// and class types may not define operator<, but typically support operator!=.