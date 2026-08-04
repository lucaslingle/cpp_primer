/*
Which if any of the following static data member declarations and
definitions are errors? Explain why?
```
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};

// example.cc
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
*/

// the static double rate cannot be initialized inside Example 
// since it is not constant or constexpr. same goes for vec.
//
// if the earlier initializations were amended to be declarations only,
// the declarations in example.cc for both rate and vec are default initializations,
// which might not have been the authors' intent. 
