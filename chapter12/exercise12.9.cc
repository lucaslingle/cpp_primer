/*
Explain what happens in the following code:
```
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
*/

// int *q = new int(42), *r = new int(100);
// this line allocates two int objects in dynamic memory (heap memory),
// assigns values 42 and 100 to them, and points to them with pointers q and r.
//
// r = q;
// this line changes the pointer r to point to q, which means there is no way to delete
// the original object pointed to by r. the result is a memory leak.
//
// auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
// this line allocates two int objects in dynamic memory (heap ememory),
// assigns values 42 and 100 to them, and points to them with shared_ptrs q2 and r2.
//
// r2 = q2;
// this line decrements the reference count for the original r2 shared_ptr,
// and since it reached 0, the underlying object is deleted.
// it also increments the reference count for the q2 shared_ptr,
// which now reaches 2.
// the variable r2 is then copy-assigned from shared_ptr q2, so both shared_ptrs
// point to the same object in dynamic memory and both know the reference count is 2.
