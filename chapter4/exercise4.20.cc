/*
Assuming that iter is a vector<string>::iterator 
indicate which if any of the following expressions are legal.
Explain the behavior of the legal expressions 
and why those that aren't legal are in error. 

(a) *iter++;
(b) (*iter)++;
(c) *iter.empty();
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
*/

// (a) is valid. the postfix ++ binds higher than dereference, 
// the postfix increments the location of the iterator 
// and returns an rvalue copy of the current iterator prior to incrementing, 
// which is what is subject to the dereference.

// (b) is invalid. the parentheses force the dereference operator 
// to be applied to the iterator, but then the postfix increment operator is applied 
// to a string, which does not support this operator. 

// (c) is invalid. the dot operator has higher precedence than indirection,
// but iter.empty() is not a valid operator for iterators.

// (d) is valid. the arrow operator is applicable to pointers and iterators. 
// here it takes the current item stored in iter and calls the dot operator on it,
// i.e. (*iter).empty(), checking if current item in iterator is an empty string. 

// (e) is invalid. the dereferencing operator is applied to iterator, 
// producing a string, but the string is then subject to an increment operator.

// (f) is valid. it increments the position of the iterator, 
// but uses its current position prior to incrementing to 
// check if that item is an empty string. 
