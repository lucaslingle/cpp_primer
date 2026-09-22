/*
Is the following function legal? If not why not? If it is legal
what if any are the restrictions on the argument type(s) that can be passed,
and what is the return type?
```
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) 
{
    return *beg;
}
```
*/

// The function is legal. 
// The template type `It` must be a pointer or an input iterator,
// and the underlying type must support addition with an integer. 
//
// The return type is a non-reference value representing 
// the promoted element type after undergoing integer addition. 