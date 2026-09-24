/*
Explain what happens in each of the following calls:
```
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

g(42);
g(p);
g(ci);
g(p2);

f(42);
f(p);
f(ci);
f(p2);
```
*/

// g(42) - No way to deduce a pointer type T* from this, resolves to g(T), T = int.
// g(p) - Either g(T) with T = int*, or g(T*) with T = int. 
//     The second is more specific; resolves to g(T*), T = int.
// g(ci) - No way to deduce a pointer type T* from this, and top-level const is dropped,
//    resolves to g(T), T = int.
// g(p2) - Either g(T) with T = const int*, or g(T*) with T = const int. 
//    The second is more specific; resolves to g(T*), T = const int.

// f(42) - No way to deduce a pointer type T* from this, resolves to f(T), T = int.
// f(p) - Either f(T) with T = int* or f(const T*) with T = int. 
//    Second option adds low level const, first is exact match. 
//    Resolves to f(T) with T = int*.
// f(ci) - No way to deduce a pointer type T* from this. Top level const is dropped. 
//    Resolves to f(T), T = int.
// f(p2) - Either f(T) with T = const int*, or f(const T*) with T = int. Low level const is kept. 
//    The second is more specific; resolves to f(const T*), T = int.