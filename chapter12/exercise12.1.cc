/*
How many elements do b1 and b2 have at the end of this code?
```
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```
*/

// from the main text of the book, StrBlob has only one data member, 
// a shared_ptr to a vector of strings. 
// 
// Using the initializer list constructor defined in the main text of the book,
// we can conclude this data member is written to in the list initialization of b2.
//
// Thus, b2 initially stores three elements, before its shared_ptr is copied
// to b1 using the default copy assignment operator. 
// 
// Then, an additional element is added to b2. Since b1 and b2 both share
// a shared_ptr, they both point to the same dynamic memory (heap memory),
// and both have four elements. 
// 
// After the curly braces end, b2 is destroyed.
// The reference count for the shared_ptr is decremented but remains > 0.
// Only b1 remains, and it continues to have access to the data via the shared_ptr.
