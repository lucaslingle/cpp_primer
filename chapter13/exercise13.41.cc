/*
Why did we use postfix increment in the call to `construct`
inside `push_back`? What would happen if we used prefix increment?
*/

// first_free points to the first free element,
// so to write to the location it points to we need to use postfix increment.
// if we use prefix increment, that location will be skipped over.
