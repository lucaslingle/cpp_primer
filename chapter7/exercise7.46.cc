/*
Which if any of the following statements are untrue? Why?
(a) A class must provide at least one constructor.
(b) A default constructor is a constructor with an empty parameter list.
(c) If there are no meaningful default values for a class, the class should
    not provide a default constructor.
(d) If a class does not define a default constructor, the compiler generates
    one that initializes each data member to the default value of its associated type.
*/

// (a) is false. the synthesized default constructor is included automatically 
// if there are no user-defined constructors.

// (b) is false. a constructor with default arguments for all parameters in its 
// parameter list would also be a default constructor.  

// (c) is false. if the class type is used in other contexts, such as in a vector,
// it would be desirable for the vector to be constructable using e.g., value initialization,
// which would require a default constructor to be used for the vector elements.

// (d) is false. although a default constructor will be constructed, 
// not all data members may have a default value. in addition, if there are in-class 
// initializers for some data members, those will be used, where supplied.
