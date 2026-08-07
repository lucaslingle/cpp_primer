/*
Rewrite the previous function using an index and a replace.
*/

#include <iostream>
#include <string>

void string_edit(std::string &s, 
                 const std::string &oldVal, 
                 const std::string &newVal) {
    int index = 0;
    while (index != s.size()) {
        if (s.substr(index, oldVal.size()) == oldVal) {
            s = s.replace(index, oldVal.size(), newVal);
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
