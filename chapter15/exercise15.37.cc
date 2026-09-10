/*
What changes would your classes need if the derived classes had
members of type `shared_ptr<Query_base>` rathe than of type `Query`?
*/

// the type query has one data member, `shared_ptr<Query_base> q`
// and has two non-constructor member functions, which merely forward their
// name to be applied to data member q via the arrow operator: e.g., 
// string rep() const { return q->rep(); }

// so in general, the main changes would be changing code in the derived classes
// from using Query::rep() and Query::eval(t) to using ->rep() and ->eval(t).

// the code would obviously also need to be changed to use the new data member type.
