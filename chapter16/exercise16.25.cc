/*
Explain the meaning of these declarations
```
extern template class vector<string>;
template class vector<Sales_data>;
```
*/

// extern template class vector<string>;
//
// this is an explicit instantiation declaration. 
// it says that the class vector<string> is instantiated elsewhere
// in the program. it tells the compiler of an individual file to
// not instantiate the template, but to wait for the linker 
// of the resulting object files to find the instantiation. 

// template class vector<Sales_data>;
//
// this is an explicit instantiation definition. 
// it forces the compiler to instantiate the class template vector 
// with the type Sales_data, generating the class vector<Sales_data>.
