/*
Write three additional declarations for the function in the previous exercise.
One should use a type alias, one should use trailing return, the third should decltype.
Which do you prefer and why?

// previous exercise declaration
// string (&my_function())[10];
*/

#include <string>
using std::string;
using arrT = string[10];

string arr[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

arrT& my_function();
auto my_function() -> string(&)[10];
decltype(arr) &my_function();

// trailing return is best because return type is explicitly stated, easy to read.
