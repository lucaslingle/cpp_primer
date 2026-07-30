/*
When are friends useful? Discuss the pros and cons of using friends.
*/

// a friend of a class is a non-member function of that class
// that has access to its non-public members, both data and functions.
// 
// a friend function is useful if non-member functions require access
// to protected data or helper functions inside the class to perform their duties. 
//
// friend functions are non-member functions and their implementation must appear
// outside the class definition, which may impair readability. 
// another downside of using friend functions is that each friend function
// can alter the private state of the class, so they must be designed carefully.
// arguably, the same could be said of member functions however.
