/*
Given only the following code, explain whether each of 
these calls is legal. If so, what is the type of T? 
If not, why not?
```
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```
*/

// (a) The call is illegal. The inputs "hi" and "world" are char arrays,
// but since the template function takes a reference to T, neither is
// converted (decayed) to a pointer to the first array element. As a result,
// the inferred type would be char[3] and char[6] for the two different positions,
// leading to a type error.

// (b) The call is legal. The inputs "bye" and "dad" are char arrays,
// and both have the same length. The inferred type of T is char[4]. 
