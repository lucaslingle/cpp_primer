/*
Write a program to concatenate two string literals, putting the result
in a dynamically allocated array of char. Write a program to concatenate 
two library strings that have the same value as the literals 
used in the first program.
*/

#include <iostream>
#include <cstring>
#include <string>

int main() {
    const char *s1 = "Hello";
    const char *s2 = "World";
    auto l1 = std::strlen(s1);
    auto l2 = std::strlen(s2);
    char *p = new char[l1+l2+1];
    std::strcpy(p, s1);
    std::strcat(p, s2);
    std::cout << p << std::endl;
    delete [] p;

    std::string ss1("Earth");
    std::string ss2("Greet");    
    auto sl1 = ss1.size();
    auto sl2 = ss2.size();
    std::string ss3 = ss1 + ss2;
    char *q = new char[sl1+sl2+1];
    std::strcpy(q, ss3.c_str());
    std::cout << q << std::endl;
    delete [] q;

    return 0;
}