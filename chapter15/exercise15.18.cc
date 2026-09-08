/*
Given the classes from p. 612 and p. 613 and assuming each object has the type
specified in the comments, determine which of these assignments are legal. 
Explain why those that are illegal aren't allowed.
```
Base *p = &d1; // d1 has type Pub_Derv
p = &d2;       // d2 has type Priv_Derv
p = &d3;       // d3 has type Prot_Derv
p = &dd1;      // dd1 has type Derived_from_Public
p = &dd2;      // dd2 has type Derived_from_Private
p = &dd3;      // dd3 has type Derived_from_Protected
```

reference of hierarchy:
Base
    Pub_Derv
        Derived_from_Public
    Priv_Derv
        Derived_from_Private
    Prot_Derv
        Derived_from_Protected
*/

// Base *p = &d1;
// derived-to-base conversion is legal because Pub_Derv publicly inherits from Base

// p = &d2;
// derived-to-base conversion is illegal because Priv_Derv privately inherits from Base

// p = &d3;
// derived-to-base conversion is illegal because Prot_Derv protectedly inherits from Base

// p = &dd1;
// derived-to-base conversion is legal because Derived_from_Public inherits publicly from Pub_Derv,
// which inherits publicly from Base.

// p = &dd2;
// derived-to-base conversion is illegal because Derived_from_Private inherits from Priv_Derv,
// which does not inherit publicly from Base.

// p = &dd3;
// derived-to-base conversion is illegal because Derived_from_Protected inherits from Prot_Derv,
// which does not inherit publicly from Base.
