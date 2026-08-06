/*
Assuming iv is a vector of ints, what is wrong with the following program?
How might you correct the problem(s)?
```
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```
*/

// two problems.

// iter is never being updated, so the halting condition is never reached.
// to fix this first problem, should use the updated iterator returned by insert. 

// also, in general, inserts invalidate any iterators or references 
// to the container being inserted into. so mid may not be meaningful.
//
// one extreme way around the second problem would be to iterate through the vector
// and copy all elements into a new vector, applying the 2 * some_val prepend
// before each occurrance of some_val in the first half of the original vector.
//
// a second way would be to track the midpoint index, use it as the stopping condition,
// and update it when we insert elements in the first half so that we're tracking the element 
// corresponding to the original midpoint.
