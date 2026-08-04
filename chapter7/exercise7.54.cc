/*
Should the members of Debug that begin with set_ be declared as constexpr?
Why or why not?
*/

// constexpr functions must have a return statement only, the setter methods
// require an assignment statement as well, so they cannot be constexpr. 
