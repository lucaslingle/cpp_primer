/*
Which of the following unique_ptr declarations are illegal or likely
to result in subsequent program error? Explain what the problem is with each one.

int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
*/

// (a) error: constructing a new unique_ptr from non-pointer variable.

// (b) error: constructing a new unique_ptr from a pointer to a 
// variable allocated on the stack.

// (c) bad: pi2 is a pointer to an int variable on the heap,
// but if p2 deletes this variable, pi2 will be a dangling pointer.
// in addition, must ensure user does not call delete on pi2 directly.

// (d) error: constructing a new unique_ptr from a pointer to a 
// variable allocated on the stack.

// (e) okay: p4 is a unique_ptr initialized from a temporary pointer 
// to a variable allocated on the heap.

// (f) bad: p2.get() returns a raw pointer, so if either p5 or p2 go out of scope
// before the program ends, they will try to delete the object on the heap.
// the remaining pointer will be dangling. and if it too goes out of scope before
// the program ends, it will be a double free.
