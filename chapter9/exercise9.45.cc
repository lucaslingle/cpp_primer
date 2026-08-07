/*
Write a function that takes a string representing a name 
and two other strings representing a prefix such as "Mr." or "Ms.",
and a suffix such as "Jr." or "III". Using iterators and the insert
and append functions, generate and return a new string with the suffix
and prefix added to the given name.
*/

#include <iostream>
#include <string>

void fancy_name(std::string &name, 
                const std::string &prefix, 
                const std::string &suffix) {
    std::string spaced_prefix(prefix);
    spaced_prefix.append(" ");

    name.insert(name.cbegin(), spaced_prefix.cbegin(), spaced_prefix.cend());
    name.append(" ");
    name.append(suffix);
}

int main() {
    std::string name = "George";
    fancy_name(name, "King", "III");
    std::cout << name << std::endl;
    return 0;
}
