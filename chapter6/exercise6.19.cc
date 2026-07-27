/*
Given the following declarations, determine which calls are legal and
which are illegal. For those that are illegal explain why.

double calc(double);
int count(const string &, char);
int sum(vector<int>>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
*/

// (a) invalid, too many arguments for parameter list of length 1.
// (b) valid, C-style string literal automatically converted for parameter of type const string &.
// (c) valid, int literal automatically converted to double for parameter of type double.
// (d) valid, double literal automatically converted to int for parameter of type int.
