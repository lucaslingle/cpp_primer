/*
What would happen if you define the loop control variable in the previous exercise 
as type char? Predict the results and then change your program to use char to see
if you were right.
*/

// if we use type char instead of type auto&, it won't actually make a reference
// to each character on each iteration of the loop, and there will be no way
// to update the string.

#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char c : s)
        c = 'X';
    std::cout << s << std::endl;
    return 0;
}
