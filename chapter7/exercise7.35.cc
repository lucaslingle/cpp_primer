/*
Explain the following code, indicating which definition of Type or
initVal is used for each use of those names. Say how you would fix any errors.
```
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
*/

// typedef string Type;
// defines Type as an alias for string type.
//
// Type initVal() declares a non-member function initVal that returns a Type.
//
// The class Exercise redefines Type, which is illegal. 
//
// The class Exercise declares ```Type setVal(Type)``` which later appears to use 
// initVal()'s return in an addition with parameter ```parm```. This lead me to 
// wonder if both types are strings. However, since val is not declared within setVal,
// I ultimately decided that val refers to the private int variable in Exercise.
//
// That means parm and initVal() are arithmetic types. In this case, I believe
// both of them are meant to have the Exercise typedef of Type, i.e., double.
//
// Now we reach ```Type Exercise::setVal(Type parm)```, so we decide
// that the intended type is double in both cases. 
// To use the type alias in the return type, we need to include the scope.
// Once the scope is clear for our declared member function, there is no need 
// to reiterate the scope for the parameter type however. 
// Likewise for initVal in the function body: the intended one is the member func,
// which is the first one that will be found according to the scope rules.
// 
// Althogether we can rewrite the code as something like

typedef string SType;
SType initVal();
class Exercise {
public:
    typedef double DType;
    DType setVal(DType);
    DType initVal();
private:
    int val;
};
Exercise::DType Exercise::setVal(DType parm) {
    val = parm + initVal();
    return val;
}
