#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stdexcept>
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::unordered_map;
using std::runtime_error;

unordered_map<string, string> build_map(ifstream &tx_file) {
    unordered_map<string, string> tx;
    string key, value;
    while (tx_file >> key && getline(tx_file, value))
        if (value.size() > 1)
            tx[key] = value.substr(1);
        else
            throw runtime_error("no rule for key: " + key);
    return tx;
}

const string &transform(const string &s, const unordered_map<string, string> &m) {
    auto it = m.find(s);
    if (it != m.cend())
        return it->second;
    else
        return s;
}

void chat_transform(ifstream &tx_file, ifstream &inp_file) {
    auto tx = build_map(tx_file);
    string line;
    while (getline(inp_file, line)) {
        istringstream wordstream(line);
        string word;
        bool first = true;
        while (wordstream >> word) {
            if (first)
                first = false;
            else
                cout << " ";
            cout << transform(word, tx);
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        throw runtime_error("bad format. expected: prog.o tx_fname inp_fname");
    ifstream tx_file(argv[1]);
    ifstream inp_file(argv[2]);
    chat_transform(tx_file, inp_file);
    return 0;
}
