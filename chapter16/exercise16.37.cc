/*
The library `max` function has two function arguments and returns the 
larger of its arguments. This function has one template type parameter.
Could you call `max` passing it an `int` and a `double`? 
If so, how? If not, why not?
*/

// yes it is possible if the argument type is explicitly specified:
// max<double>(myint, mydouble);
// max<int>(myint, mydouble);
// etc. both work. 

// without explicitly specifying the template type, the call would
// fail to to an inability to deduce the template type. 
// but with an explicitly specified template type, 
// standard implicit conversion rules apply again. 