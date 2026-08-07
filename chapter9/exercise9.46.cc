/*
Rewrite the previous exercise using a position and length
to manage the strings. This time use only the insert function.
*/

#include <iostream>
#include <string>

void fancy_name(std::string &name, 
                const std::string &prefix, 
                const std::string &suffix) {
    auto prefixlen = prefix.size();
    auto namelen = name.size();
    name.insert(0, prefix);
    name.insert(prefixlen, " ");
    name.insert(prefixlen + 1 + namelen, " ");
    name.insert(prefixlen + 1 + namelen + 1, suffix);
}

int main() {
    std::string name = "George";
    fancy_name(name, "King", "III");
    std::cout << name << std::endl;
    return 0;
}
