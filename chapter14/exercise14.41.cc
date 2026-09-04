/*
Why do you suppose the new standard added lambdas? Explain when
you would use a lambda and when you would write a class instead.
*/

// I suppose lambdas were added to C++11 because they are
// significantly more succinct than writing and instantiating function objects.
//
// I would mainly use a class if the expression in the lambda were too complex 
// to read clearly, or if it was going to be called in multiple places, or if
// some kind of ongoing mutability of the function-object state was required. 