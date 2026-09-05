/*
Show the possible class-type conversion sequences for the initializations of
`ex1` and `ex2`. Explain whether the initializations are legal or not.
```
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
```
*/

// ex1: LongDouble -> double -> int or LongDouble -> float -> int
// ex2: LongDouble -> double -> float or LongDouble -> float

// as shown by running the commented code in exercise14.50_empirical.cc
// the ex1 conversion is ambiguous and the ex2 conversion is not.

// this situation with conversion operators differs from the main text
// of this section, where conversion constructors are used, not conversion operators,
// and both versions are ambiguous. 