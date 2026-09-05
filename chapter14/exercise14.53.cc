/*
Given the definition of `SmallInt` on p. 588 determine whether the following 
addition expression is legal. If so, what addition operator is used?
If not, how might you change the code to make it legal?
```
SmallInt s1;
double d = s1 + 3.14;
```

reference code:
```
class SmallInt {
friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0);
    operator int() const { return val; }
private:
    std::size_t val;
};
```
*/

// the candidate functions are 
// SmallInt operator+(const SmallInt&, const SmallInt&);
// double operator+(int, double);

// converting double to SmallInt requires one standard arithmetic conversion (double->int),
// and one user-defined conversion (int->SmallInt).
//
// converting SmallInt to int requires one user-defined conversion (SmallInt->int).

// a function is only selected if it is strictly better for at least one argument
// and no worse for any other. otherwise the best function is ambiguous. 
// because no candidate is strictly better, the call is ambiguous and illegal.

// to make it legal, we could explicitly cast SmallInt to int,
// or explicitly cast double to SmallInt. 