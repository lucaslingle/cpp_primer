/*
Write the declaration for a function that returns a reference to an array
of ten strings, without using either a trailing return, decltype, or a type alias.
*/

#include <string>
using std::string;

string (&my_function())[10];
