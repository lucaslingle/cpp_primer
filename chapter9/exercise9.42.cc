/*
Given that you want to read a character at a time into a string,
and you know you need to read at least 100 characters, how might you improve
the performance of your program?
*/

// i would say preallocate the space, and then index into the string.
// we can run something like:

string s; 
s.reserve(100);
char c;
while (cin >> c)
    s.push_back(c);
