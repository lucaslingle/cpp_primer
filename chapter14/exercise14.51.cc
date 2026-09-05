/*
Show the conversion sequences (if any) needed to call each version of `calc`
and explain why the best viable function is selected.
```
void calc(int);
void calc(LongDouble);
double dval;
calc(dval);
```
*/

// double -> int for first line calc.
// double -> longdouble for second line calc.

// arithmetic conversion (standard) is ranked higher 
// than class-type conversion (user-defined conversion),
// so first line calc will be selected.
