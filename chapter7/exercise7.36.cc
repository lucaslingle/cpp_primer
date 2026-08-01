/*
The following initializer is in error. Identify and fix the problem.
```
struct X {
    X(int i, int j): base(i), rem(base % j) { }
    int rem, base;
}
```
*/

// in a constructor initializer list, the order of initialization
// is the order of declaration, in this case, rem then base.
// in the code above, rem is initialized with the undefined value of base, mod j.
//
// to fix, we can use i and j directly in both initializers. 
// as a best practice, declarations of rem, base should match the order 
// in the constructor initializer list so i swapped those as well.

struct X {
    X(int i, int j): base(i), rem(i % j) { }
    int base, rem;
}
