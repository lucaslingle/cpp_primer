/*
Our program does no checking on the validity of either input file.
In particular, it assumes that the rules in the transformation file are all sensible.
What would happen if a line in that file has a key, one space, and then end of line?
Predict the behavior and then check it against your version of the program.
*/

// the getline part will be length zero, 
// so the local variable value will have length zero, 
// and we will throw the runtime error in the buildMap function.

// verified this: i inserted "novalue " as a new line at the top of inp_file.txt
// and got this error when running exercise11.33.cc
//
// libc++abi: terminating due to uncaught exception of type std::runtime_error: no rule for key: novalue
// zsh: abort      ./a.out tx_file.txt inp_file.txt
