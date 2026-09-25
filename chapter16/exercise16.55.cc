/*
Explain how the variadic version of `print` would execute if we 
declared the nonvariadic version of print after the definition of the 
variadic version.
*/

// The declaration of the non-variadic version of print is needed by the compiler
// in order for the variadic version's function body to make an overloaded call.
// If the declaration of the non-variadic version appears later, the only 
// function visible to the compiler will be the variadic version, resulting
// in an infinite recursion once rest... is a parameter pack of size zero. 
