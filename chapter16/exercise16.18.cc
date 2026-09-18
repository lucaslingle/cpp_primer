/*
Explain each of the following template declarations
and identify whether any are illegal. Correct each error that you find.

```
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int *);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
    template <typename Ctype> Ctype f5(Ctype a);
*/

// (a) void return type function template f1 taking arguments of type T, U, V.
// illegal as written. missing typename keyword in front of U in template params list.

// (b) T return type function template f2 taking a reference to an int named T.
// illegal as written. T is a template parameter and cannot be shadowed or redefined as
// a variable name. 

// (c) T return type function template foo taking arguments of type T and unsigned int*.
// illegal as written. inline keyword should follow template and preceed return type.

// (d) unspecified return type function template f4 taking arguments of type T, T.
// illegal as written. f4 is an ordinary function not a constructor or destructor.
// it must have a specified return type.

// (e) Ctype return type function template f5 taking an argument of type Ctype.
// legal as written. template parameter Ctype shadows typedef Ctype above.
