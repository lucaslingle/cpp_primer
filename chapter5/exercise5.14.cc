/*
Write a program to read strings from standard input looking for duplicated words.
The program should find places in the input where one word is followed immediately
by itself. Keep track of the largest number of times a single repetition occurs
and which word is repeated. Print the maximum number of duplicates, or else 
print a message saying that no word was repeated. For example if the input is
```
how now now now brown cow cow
```
the output should indicate that the word now occurred three times.
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    bool start = true;
    string prevword;
    string word;
    vector<string> vocab;
    vector<int> max_dupes;
    int current_dupes = 1;
    int vocab_idx = 0;

    while (cin >> word) {
        if (word != prevword) {
            // reset streak
            current_dupes = 1;
            // get current word index
            vocab_idx = 0;
            for (auto w : vocab) {
                if (w == word)
                    break;
                ++vocab_idx;
            }
            // add new word stats if necessary
            if (vocab_idx >= vocab.size()) {
                vocab.push_back(word);
                max_dupes.push_back(1);
            }
            // prep for next word
            prevword = word;
        } else {
            // continue streak: 
            // keep word, prevword the same.
            // don't update vocab vector.
            // keep max_dupes the same til streak ends.
            // increment current_dupes.
            ++current_dupes;
        }

        // handle bookkeeping for streak
        if (current_dupes > max_dupes[vocab_idx])
            max_dupes[vocab_idx] = current_dupes;
        start = false;
    }

    for (decltype(vocab)::size_type i = 0; i < vocab.size(); ++i)
        cout << vocab[i] << ": " << max_dupes[i] << endl;

    return 0;
}
