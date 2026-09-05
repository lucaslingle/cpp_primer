/*
Explain the difference between these two conversion operators:
```
struct Integral {
    operator const int();
    operator int() const;
}
```
*/

// The first converts an Integral instance to a const int, 
// which is equivalent to int because the return is an rvalue anyway. 
// It is not const-qualified, it cannot be called on const instances of Integral.

// The second converts an Integral instance to an int.
// It is const-qualified, which indicates that the conversion operator 
// does not modify the data members, and allows it to be called on 
// const and non-const instances of Integral.