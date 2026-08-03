/*
Is the following declaration legal? If not why not?
```
vector<NoDefault> vec(10);
```
*/

// The vector initializer here uses value initialization.
// If the NoDefault class lacks a default constructor, 
// the declaration is illegal because default constructors are used 
// in scenarios requiring default initialization or value initialization.
