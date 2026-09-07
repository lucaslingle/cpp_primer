/*
Which of the following declarations, if any, are incorrect? Explain why.
```
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```
*/

// (a) inherits from itself it the class derivation list, which is illegal.
// (b) is a valid class definition.
// (c) is an invalid class declaration, because it includes the class derivation list,
// which should only be supplied during class definition.
