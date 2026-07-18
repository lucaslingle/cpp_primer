/*
Write a program to define two character arrays initialized from string literals.
Now define a third character array to hold the concatenation of the two arrays.
Use strcpy and strcat to copy the two arrays into the third.
*/

#include <iostream>
#include <cstring>

int main() {
    char cs1[10] = "hello";
    char cs2[10] = "world";

    char cs3[100];
    strcpy(cs3, cs1);
    strcat(cs3, cs2);
    std::cout << cs3 << std::endl;

    return 0;
}