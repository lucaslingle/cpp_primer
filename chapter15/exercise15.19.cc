/*
Assume that each of the classes from p. 612 and p. 613 
has a member function of the form
```
void memfcn(Base &b) { b = *this; }
```
For each class, determine whether this function would be legal.


reference of hierarchy:
```
Base
    Pub_Derv
        Derived_from_Public
    Priv_Derv
        Derived_from_Private
    Prot_Derv
        Derived_from_Protected
```
*/

// since b is a Base&, this is an example of a derived-to-base conversion.
// the difference from the previous problem is that we are now looking at
// derived classes rather than user code.

// Base: legal
// Pub_Derv: legal
// Priv_Derv: legal
// Prot_Derv: legal
// Derived_from_Public: legal
// Derived_from_Private: illegal
// Derived_from_Protected: legal