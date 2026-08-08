/*
Write a program to process a vector<string> whose elements represent integral values.
Produce the sum of all the elements in that vector.
Change the program so that it sums strings that represent floating-point values.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int svec_sum_int(const std::vector<std::string> &svec) {
    int sum = 0;
    for (auto &item : svec)
        sum += std::stoi(item);
    return sum;
}

double svec_sum_double(const std::vector<std::string> &svec) {
    double sum = 0.0;
    for (auto &item : svec)
        sum += std::stod(item);
    return sum;
}

int main() {
    std::vector<std::string> svec1 = {"1", "2", "3", "42", "100"};
    std::vector<std::string> svec2 = {"1.0", "2.5", "3.5", "41.0", "100.0"};
    std::cout << svec_sum_int(svec1) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << svec_sum_double(svec2) << std::endl;
    return 0;
}
