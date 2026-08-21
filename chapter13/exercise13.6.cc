/*
What is a copy-assignment operator?
When is this operator used?
What does the synthesized copy-assignment operator do?
When is it synthesized?
*/

// The copy-assignment operator is used when assigning a class type variable 
// to another variable of the same class type. It is used when both 
// variables are already initialized. 

// The synthesized copy-assignment operator assigns each data member of a class
// type variable to another class type variable. It does so by calling the
// copy-assignment operator of each data member. It also returns a reference 
// to the left-hand operand. 

// It is synthesized when a copy-assignment operator is not supplied by
// the user. A copy-assignment operator looks like ```T& T::operator=(const T& t)```. 
