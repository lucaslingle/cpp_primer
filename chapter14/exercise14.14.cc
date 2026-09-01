/*
Why do you think it is more efficient to define operator+ to call operator+=
rather than the other way around?
*/

// if operator+= called operator+(*this, other)
// then the operator+ would return the result by value, which would then 
// have to be copied/moved into the data members of *this. 
//
// so a temporary object is created and superfluous copies occur this other way. 