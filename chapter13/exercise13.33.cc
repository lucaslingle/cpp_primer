/*
Why is the parameter to the `save` and `remove` members of `Message`
a `Folder&`? Why didn't we define that parameter as a `Folder`?
Or `const Folder&`?
*/

// If it was a `Folder`, the Folder argument would be passed by value,
// i.e., a copy would be made locally to `save` and `remove`, preventing
// any changes to the original argument passed at the call site.

// If it was a `const Folder&`, the member functions `addMsg` and `remMsg`
// would not work to update the set of message pointers in the Folder object,
// because the object would be reference to const.
