/*
What kinds of classes need a virtual destructor?
What operations must a virtual destructor perform?
*/

// Any class B that wants to be deleted polymorphically needs a virtual destructor,
// otherwise deleting pointers of type B* to a derived class object D 
// leads to undefined behavior. 
//
// A virtual destructor should act like a normal destructor for the base class.
// Its true purpose is to ensure that the delete call applies the destructor
// for the derived class.
