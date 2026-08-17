/*
Using the declarations of p and sp explain each of the following calls
to ```process```. If the call is legal, explain what it does.
If the call is illegal, explain why:

auto p = new_int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
*/

// (a) calls process on the shared_ptr sp, which is perfect, 
// because that's the type it expects. inside the function call,
// the stored reference count of sp is 2, 
// and once it returns, the count drops to 1.

// (b) calls process on the pointer returned by ```new int()```,
// which is not a shared_ptr and has no implicit conversion to shared_ptr,
// so the program will not compile.

// (c) calls process on the pointer p, 
// which is not a shared_ptr and has no implicit conversion to shared_ptr,
// so the program will not compile.

// (d) calls process on the temporary shared ptr shared_ptr<int>(p),
// which is a shared_ptr with reference count 1 inside process.
// once process returns, the count drops to zero and the object pointed to by p
// is deleted (assuming it is allocated on the heap, otherwise it is undefined behavior).
// the result is that p is a dangling pointer. 
