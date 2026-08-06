/*
In the first program in this section on page 346, what would the values of
val, val2, val3, and val4 be if c.size() is 1?

reference code:
```
if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();
    auto last = c.end();
    auto val3 = *(--last);
    auto val4 = c.back();
}
```
*/

// val and val2 would be the first element.
//
// last would point one past the end of the array, 
// so val3 = *(--last) would be the first element
//
// and val4 would be the last element of the length-1 container, 
// which is the first element. 
