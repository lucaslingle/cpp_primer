/*
Extend the program that assigned high pass, pass, and fail grades to also 
assign low pass for grades between 60 and 75 inclusive. 

Write two versions: one version that uses only conditional operators;
the other should use one or more if statements. 
Which version is easier to understand and why. 
*/

#include <iostream>
#include <string>

char *categorize_v1(int grade) {
    return (grade > 90) ? "high pass"
         : (grade > 75) ? "pass"
         : (grade <= 75 && grade >= 60) ? "low pass"
         : "fail";
}

// second version is easier to read, perhaps because 
// we dont have to parse how the ternary expressions nest. 
char *categorize_v2(int grade) {
    if (grade > 90)
        return "high pass";
    if (grade > 75)
        return "pass";
    if (grade <= 75 && grade >= 60)
        return "low pass";
    return "fail";
}
