/*
Using an if-else statement, write your own version of the program 
to generate a letter grade from a numeric grade.
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

    if (numeric_grade < 60)
        std::cout << letters[0] << std::endl;
    else {
        letter_grade = letters[(numeric_grade - 50) / 10];
        if (numeric_grade != 100) {
            if (numeric_grade % 10 < 3)
                letter_grade += "-";
            if (numeric_grade % 10 > 7)
                letter_grade += "+";
        }
        std::cout << letter_grade << std::endl;
    }

    return 0;
}
