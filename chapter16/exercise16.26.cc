/*
Assuming `NoDefault` is a class that does not have a default constructor
can we explicitly instantiate `vector<NoDefault>`? If not why not?
*/

// The answer is no, we cannot explicitly instantate vector<NoDefault>.
// The reason is that explicit instantiations of class templates 
// differ from implicit instantiations, and always generate all member functions
// for the class. The member function vector<T>::resize requires 
// value initialization for type T when calling vec.resize(n) with n > vec.size().
// Since there is no default constructor for NoDefault, this member function
// cannot be used, and a type error will occur. 