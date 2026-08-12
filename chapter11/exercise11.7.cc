/*
Define a map for which the key is the family's last name
and the value is a vector of the children's names. Write code to add new families
and add new children to an existing family.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using String = std::string;
using NameVec = std::vector<String>;
using FamStruct = std::map<String, NameVec>;

void add_family(FamStruct &f, const String &lastname) {
    NameVec vec;
    f[lastname] = vec;
}

void add_child(FamStruct &f, const String &lastname, const String &firstname) {
    f[lastname].push_back(firstname);
}

void print_fams(FamStruct &f, std::ostream &outp) {
    for (auto kv : f) {
        outp << kv.first << ": ";
        for (auto v : kv.second)
            outp << v << ", ";
        outp << std::endl;
    }
}

int main() {
    FamStruct fams;

    add_family(fams, "Addams");
    add_family(fams, "Soprano");

    add_child(fams, "Addams", "Wednesday");
    add_child(fams, "Addams", "Pugsley");

    add_child(fams, "Soprano", "Meadow");
    add_child(fams, "Soprano", "Tony Jr.");

    print_fams(fams, std::cout);
    return 0;
}
