/*
Which `operator+` if any is selected for each of the addition expressions?
List the candidate functions, the viable functions, and the type conversions
on the arguments for each viable function:
```
class SmallInt {
friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0);
    operator int() const { return val; }
private:
    std::size_t val;
};

struct LongDouble {
    // member operator+ for illustration purposes, operator+ is usually nonmember
    LongDouble operator+(const SmallInt&);
    LongDouble(double db = 0.0);
    operator double();
    operator float();
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```
*/

// - candidate functions are either nonmember functions whose names match the name at the call site,
//   or member functions whose the left-hand operand is of the class type given. 
// - viable functions are candidate functions with a parameter count match 
//       and implicit conversion compability. 

// for ld = si + ld;
//
// the candidates are:
// SmallInt operator+(const SmallInt&, const SmallInt&);
// LongDouble operator+(LongDouble&, double);
// plus the built-in operator+ functions for doubles, floats, ints, etc.
//
// the viable functions are:
// the built-in operator+ functions for doubles, floats, ints, etc.
//     requires type conversion of ld operand to double or float, and perhaps to int.
//     requires type conversion of si operand to int, and perhaps to double or float.
//     requires the return type to be cast back to LongDouble.
//
// among these viable functions, all require at least one user-defined conversions,
// leading to ambiguity. e.g., operator+(int, float) vs operator+(int, double).
// no operator+ is selected, and a compilation error occurs.

// for ld = ld + si;
//
// the candidates are:
// LongDouble operator+(LongDouble&, double);
// LongDouble LongDouble::operator+(const SmallInt&);
// plus the built-in operator+ functions for doubles, floats, ints, etc.
//
// the viable functions are:
// LongDouble operator+(LongDouble&, double);
//    requires type conversion of si operand to int and then double.
// 
// LongDouble LongDouble::operator+(const SmallInt&);
//    requires no type conversions.
//
// plus the built-in operator+ functions for doubles, floats, ints, etc.
//     requires type conversion of ld operand to double or float, and perhaps to int.
//     requires type conversion of si operand to int, and perhaps to double or float.
//     requires return type to be cast back to LongDouble.
//
// among the viable functions, LongDouble LongDouble::operator+(const SmallInt&)
// is a perfect match and is selected.
