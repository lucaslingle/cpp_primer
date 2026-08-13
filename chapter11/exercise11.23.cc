/*
Rewrite the map that stored vectors of children's names with a key
that is the family last name for the exercises on p. 424 to use a multimap.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using String = std::string;
using FamStruct = std::multimap<String, String>;

void add(FamStruct &f, const String &lastname, const String &firstname) {
    f.insert({lastname, firstname});
}

void print_fams(FamStruct &f, std::ostream &outp) {
    for (auto kv : f)
        outp << kv.first << ", " << kv.second << std::endl;
}

int main() {
    FamStruct fams;

    add(fams, "Addams", "Wednesday");
    add(fams, "Addams", "Pugsley");

    add(fams, "Soprano", "Meadow");
    add(fams, "Soprano", "Tony Jr.");

    print_fams(fams, std::cout);
    return 0;
}
