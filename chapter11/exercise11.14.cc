/*
Extend the map from family name to children that you wrote for exercise 11.7
by having the vector store a pair that holds the child's name and birthday.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using String = std::string;
using Pair = std::pair<String, String>;
using PairVec = std::vector<Pair>;
using FamStruct = std::map<String, PairVec>;

void add_family(FamStruct &f, const String &lastname) {
    PairVec vec;
    f[lastname] = vec;
}

void add_child(FamStruct &f, const String &lastname, const String &firstname, const String &birthday) {
    f[lastname].emplace_back(firstname, birthday);
}
