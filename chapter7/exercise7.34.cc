/*
What would happen if we put the typedef of pos in the Screen class on line 285
as the last line of the class?

reference code:
```
int height;
class Screen {
public:
    typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
}
```
*/

// although member function bodies can resolve data members and member types
// from anywhere in the class, the same is not true of member function signatures.
// the definition of any type in the function signature must be resolvable
// based solely on what has been seen "thus far". 
// 
// thus, sticking the typedef at the end would break the code.
