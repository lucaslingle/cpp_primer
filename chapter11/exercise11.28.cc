/*
Define and initialize a variable to hold the result of calling find 
on a map from string to vector of int.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main() {
    map<string, vector<int>> m = {{"Hello", {1, 2, 3}}, {"World", {4, 5}}};
    map<string, vector<int>>::iterator result = m.find("World");
    for (auto i : result->second)
        cout << i << " ";
    cout << endl;
    return 0;
}
