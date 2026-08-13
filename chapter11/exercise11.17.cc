/*
Assuming c is a multiset of strings and v is a vector of strings,
explain the following calls. Indicate whether each call is legal:
```
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
```
*/

// copy(v.begin(), v.end(), inserter(c, c.end()))
// insert is supported by multisets, so inserter can be used to make c 
// the copy destination.

// copy(v.begin(), v.end(), back_inserter(c))
// push_back is not supported by multisets, so back_inserter cannot be used to make c 
// the copy destination. 

// copy(c.begin(), c.end(), inserter(v, v.end()))
// c is a container and supports the iterator beginning and end member functions,
// so this call is valid.

// copy(c.begin(), c.end(), back_inserter(v));
// c is a container and supports the iterator beginning and end member functions,
// so this call is valid.