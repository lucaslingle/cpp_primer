/*
Assuming `s` is a `string`, explain `svec.emplace_back(s)`.
*/

// emplace_back is a variadic template member function of `vector<string>`
// which is itself an instantiated class template. 

// emplace_back works by constructing an element in preallocated heap memory,
// contiguous to the previous elements stored by `svec`, 
// and it does so by using perfect forwarding on the passed arguments,
// in this case calling the appropriate constructor for an lvalue reference to string. 

// In this case, since `s` is a `string` variable, 
// it is used in the string copy constructor. 
// (Since `s` is an lvalue, it is not used with the move constructor.)
