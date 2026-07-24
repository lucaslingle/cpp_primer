/*
Rewrite your grading program to use the conditional operator 
in place of the if-else statement. 
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> letters = {"F", "D", "C", "B", "A", "A++"};
    std::string letter_grade;
    int numeric_grade;

    std::cout << "numeric grade?" << std::endl;
    std::cin >> numeric_grade;
    std::cout << "letter grade: " << std::endl;

    letter_grade = (numeric_grade < 60) ? letters[0] : letters[(numeric_grade - 50) / 10];
    letter_grade += (numeric_grade < 60 || numeric_grade == 100) ? "" : ((numeric_grade % 10 < 3) ? "-" : "");
    letter_grade += (numeric_grade < 60 || numeric_grade == 100) ? "" : ((numeric_grade % 10 > 7) ? "+" : "");

    std::cout << letter_grade << std::endl;
    return 0;
}
