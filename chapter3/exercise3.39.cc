/*
Write a program to compare two strings. Now write a program to compare 
the values of two C-style character strings.
*/

#include <iostream>
#include <string>
#include <cstring>

int compare_string(std::string s1, std::string s2) {
    if (s1 < s2)
        return -1;
    else if (s2 > s1)
        return 1;
    else
        return 0;
}

int compare_cstring(char *s1, char *s2) {
    return std::strcmp(s1, s2);
}

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";

    char cs1[] = "hello";
    char cs2[] = "world";

    std::cout << compare_string(s1, s2) << std::endl;
    std::cout << compare_cstring(cs1, cs2) << std::endl;

    return 0;
}
