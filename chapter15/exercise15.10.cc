/*
Recalling the discussion from p. 311, explain how the program on p. 317
that passed an `ifstream` to `Sales_data` friend function `read` works.
*/

// The `std::istream& read(std::istream&, Sales_data&)` function takes a reference
// to an istream, and since istream is the base class (direct or indirect) 
// of ifstream, C++ allows a derived-to-base conversion, 
// enabling an instance of ifstream to be passed to a reference to istream. 
// At runtime, the dynamic type of the first argument to `read`
// would then be an ifstream, while the static type is an istream. 
