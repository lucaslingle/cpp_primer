/*
Assuming class D1 on p. 620 had intended to override its inherited `fcn` function,
how would you fix that class? Assuming you fixed the class so that `fcn` matched
the definition in `Base`, how would the calls in that section be resolved?
*/

// to override the `void fcn()` declared in `Base`,
// you would have to use the signature `void fcn()` instead of `void fcn(int)`
// as is currently written in the `D1` derived class.
// as a best practice, one would also use the override keyword.

// if you fixed it as specified, the calls in that section 
// would be resolved as follows:

// Base bobj; D1 d1obj; D2 d2obj;
// Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
// bp1->fcn();  // virtual call Base::fcn at runtime
// bp2->fcn();  // virtual call D1::fcn at runtime
// bp3->fcn();  // virtual call D2::fcn at runtime
