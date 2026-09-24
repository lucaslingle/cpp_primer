/*
Explain this loop from `StrVec::reallocate` in section 13.5 (p. 530):
```
for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++))
```
*/

// elem is a pointer that iterates over the old elements, 
// which are stored contiguously.

// *elem++ increments the pointer, returns the old pointer as an rvalue,
// and then dereferences the old pointer, yielding an lvalue reference 
// to the old element pointed to prior to incrementing.

// std::move is a function template which returns an rvalue reference
// bound to this lvalue reference, permitting the programmer to remove
// the internals of the referenced element (in this case a string),
// and replace them with other values so long as the element 
// is left in a valid state. 

// alloc.construct takes a pointer to the location where an element should
// be constructed, along with arguments for a constructor of type string.
// this works because alloc is a class template instantiated with type string.

// in this case, alloc.construct invokes the move constructor for strings.
// it copies the char* pointer inside the rvalue referenced string, 
// along with whatever else is needed, and it replaces the stored pointer
// in the lvalue reference to something else, so the lvalue referenced string 
// can be safely destroyed without deleting the characters on the heap. 
