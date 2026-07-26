/*
Assuming T is the name of a type explain the difference between a function declared as 
```void f(T)``` and ```void f(T&)```.
*/

// the second function has a reference to type T as its parameter.
// this allows it to avoid copying large objects (if type T instances are),
// and it allows accessing type T objects if type T objects cannot be copied,
// and it allows changing the value stored in the object of type T.
//
// the first function always makes a copy of the object of type T, 
// and cannot change the value stored in the argument.
//
// additionally, the second function *can* take an input of type T as the argument, 
// and will create a reference to the argument automatically.
