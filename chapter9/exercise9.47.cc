/*
Write a program that finds each numeric character and then each
alphabetic character in the string "ab1c2d8EF9". Write two versions
of the program. The first should use find_first_of, and the second 
find_first_not_of.
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<char> findall_v1(const std::string &s, const std::string &q) {
    std::vector<char> vec;
    std::string::size_type pos = 0;
    while ((pos = s.find_first_of(q, pos)) != std::string::npos) {
        vec.push_back(s[pos]);
        ++pos;
    }
    return vec;
}

std::vector<char> findall_v2(const std::string &s, const std::string &q) {
    std::vector<char> vec;
    std::string::size_type pos = 0;
    while ((pos = s.find_first_not_of(q, pos)) != std::string::npos) {
        vec.push_back(s[pos]);
        ++pos;
    }
    return vec;
}

std::string get_alphabet() {
    std::string alphabet;
    alphabet.reserve(52);
    for (char c = 'a'; c <= 'z'; ++c)
        alphabet += c;
    for (char c = 'A'; c <= 'Z'; ++c)
        alphabet += c;
    return alphabet;
}

std::string get_nums() {
    std::string nums;
    nums.reserve(10);
    for (char c = '0'; c <= '9'; ++c)
        nums += c;
    return nums;
}

void print_vec(std::vector<char> vec) {
    for (auto c : vec)
        std::cout << c << " ";
    std::cout << std::endl;
}

int main() {
    std::string alnums = "ab1c2d8EF9";
    std::cout << alnums << std::endl;

    std::cout << "v1:" << std::endl;
    std::cout << "\talphabet:" << std::endl;
    auto alpha_v1 = findall_v1(alnums, get_alphabet());
    std::cout << "\t\t";
    print_vec(alpha_v1);
    std::cout << "\tnums:" << std::endl;
    auto nums_v1 = findall_v1(alnums, get_nums());
    std::cout << "\t\t";
    print_vec(nums_v1);

    std::cout << "v2:" << std::endl;
    std::cout << "\talphabet:" << std::endl;
    auto alpha_v2 = findall_v2(alnums, get_nums());
    std::cout << "\t\t";
    print_vec(alpha_v2);
    std::cout << "\tnums:" << std::endl;
    auto nums_v2 = findall_v2(alnums, get_alphabet());
    std::cout << "\t\t";
    print_vec(nums_v2);
    
    return 0;
}
