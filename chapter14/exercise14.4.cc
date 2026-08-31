/*
Explain how to decide whether the following should be class members.
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
*/

// (a) this is not assignment, subscript, call, or member access arrow,
// and it is not compound assignment, presumably does not change the state of the object,
// and it might be a symmetric operator. all of this suggests non-member.

// (b) this is a compount assignment operator, and so should be a class member.

// (c) this changes the state of the object, and so should be a class member.

// (d) this is member access arrow, and MUST be a class member.

// (e) this is not assignment, subscript, call, or member access arrow,
// and it is not compound assignment, presumably does not change the state of the object,
// and it might be a symmetric operator 
// (though that would be confusing, since neither stream writing nor bit shift are). 
// all of this suggests non-member.

// (f) this is a symmetric operator and should be a non-member, 
// so that it can be used with implicitly conversions in either order 
// (similar to int + double vs double + int). overloading && is highly discouraged.

// (g) this is an equality operator and is symmetric, so should be a non-member,
// so that it can be used with implicitly conversions in either order 
// (similar to int + double vs double + int).

// (h) this is a call operator and MUST be a class member.