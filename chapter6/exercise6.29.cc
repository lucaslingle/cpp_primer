/*
When you use an initializer_list in a range for, 
would you ever use a reference as the loop control variable?
Why or why not?
*/

// if the elements of the initializer_list are large,
// using a reference avoids copying them, so yes i might use a reference
// for the loop control variable. 
// 
// i would probably make it constant, because it isn't likely i would need to 
// modify any element of initializer_list. 
