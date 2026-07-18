/*
What would happen if we did not initialize 
the scores array in the program on page 116?
*/

// the scores array is indexed into but never assigned to,
// it is only incremented at specific indices.
//
// if it were not value initialized to all zeros, 
// it would use default initialization for its base type int, 
// so assuming scores is defined inside a function, 
// it would contain undefined values for each element.
// in that case, incrementing would not make sense.
