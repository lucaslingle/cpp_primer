/*
Write a function that takes three strings: s, oldVal, and newVal.
Using iterators, and the insert and erase functions, replace all instances
of oldVal that appear in s by newVal. Test your function by using it to replace
common abbreviations, such as "tho" by "though" and "thru" by "through".
*/

#include <iostream>
#include <string>

void string_edit(std::string &s, 
                 const std::string &oldVal, 
                 const std::string &newVal) {
    int index = 0;
    while (index != s.size()) {
        // std::cout << s[index] << std::endl;
        if (s.substr(index, oldVal.size()) == oldVal) {
            s = s.erase(index, oldVal.size());
            s = s.insert(index, newVal);
            index += newVal.size();
        } 
        ++index;
    }
}

int main() {
    char sentence[] = "i went to the drive thru tho it is unhealthy.";
    std::cout << sentence << std::endl;

    std::string s1(sentence);
    string_edit(s1, "tho", "though");
    std::cout << s1 << std::endl;

    std::string s2(sentence);
    string_edit(s2, "thru", "through");
    std::cout << s2 << std::endl;

    return 0;
}
