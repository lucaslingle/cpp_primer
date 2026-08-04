/*
What is a static class member? What are the advantages of static members?
How do they differ from ordinary members?
*/

// a static data member is associated with the class itself, 
// rather than its instances. the advantages are that if there is some data
// to be shared among all instances, it only has to be stored and/or updated once.
// one difference from ordinary members is they are not initialized inside the class,
// unless they are const or constexpr. 
//
// a static function member is also associated with the class itself,
// but unlike an ordinary function member it has no access to the `this` pointer,
// and can only access data members that are static.
