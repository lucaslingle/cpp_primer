/*
In the program on page 354, would it be legal to write 
the call to insert as follows? If not why not?
```
iter = vi.insert(iter, *iter++)
```
*/

// the order of evaluation for arguments is undefined, so 
// it is unclear whether first argument corresponds to 
// the incremented or unincremented iterator.
// the program's behavior is undefined, so the expression is illegal.
