/*
What is a copy constructor? When is it used?
*/

// A copy constructor for a class of type T is a constructor 
// that has a leading parameter of type T&, 
// followed by zero or more parameters with default values.

// A synthesized copy constructor is created for a class
// where a copy constructor is not defined by the user.
// It copies the data members of the inputted reference object
// to the respective members of the object being copied into,
// by applying the copy constructors for the respective data members.

// A copy constructor is used during copy initialization,
// and when we pass an argument to parameter of nonreference type,
// and when we return a result from a function of nonreference return type,
// and when we brace initialize elements of an array or aggregate class.
