/*
Reviwe programs you've written for the earlier exercises and decide 
whether they should be defined as inline. If so, do so. 
If not explain why they should not be inline.
*/

// 6.3 wont work here because recursive
int fact(int n) {
    int result = 1;
    while (n >= 1)
        result *= n--;
    return result;
}

// 6.4
// same

// 6.5
inline double abs(double x) {
    return (x < 0) ? -x : x;
}

// 6.7, this is actually valid though i wouldntve known it without googling
inline int counter() {
    static int n = 0;
    return n++;
}

// 6.10
inline void myswap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// 6.11
inline void reset(int &i) {
    i = 0;
}

// 6.12
inline void myswap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 6.16
inline bool is_empty(const string &s) {
    return s.empty();
}

// 6.17 let's say no, because loop count may be unknown at compile time.
bool any_uppercase(const string &s) {
    for (auto c : s)
        if (c == toupper(c))
            return true;
    return false;
}

// 6.17 let's say no, because loop count may be unknown at compile time.
void to_lowercase(string &s) {
    for (auto &c : s)
        c = tolower(c);
}

// 6.21
inline int func(int n, const int *p) {
    return (n > *p) ? n : *p;
}

// 6.22
inline void pointerswap(int *(&p), int *(&q)) {
    int *temp = p;
    p = q;
    q = temp;
}

// 6.23 this one yes
inline void print(int i) {
    std::cout << i << std::endl;
}

// 6.23 this one say no, because loop count may be unknown at compile time.
inline void print(const int ia[], std::size_t size) {
    for (std::size_t i = 0; i != size; ++i)
        std::cout << ia[i] << std::endl;
}

// 6.27 debatable if inline call will be ignored
inline int summation(std::initializer_list<int> il) {
    int sum = 0;
    for (auto elem : il)
        sum += elem;
    return sum;
}

// 6.33 won't work here because recursive
void vecprint(vector<int> v) {
    static decltype(v)::size_type index = 0;
    if (index == v.size()) {
        cout << endl;
        index = 0;
        return;
    }
    cout << v[index++] << " ";
    vecprint(v);
}

// 6.33 won't work here because recursive
void vecprint2(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg != end) {
        cout << *beg++ << " ";
        vecprint2(beg, end);
        return;
    }
    cout << endl;
}

// 6.38
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
inline decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}
inline decltype(odd) &arrRef(int i) {
    return (i % 2) ? odd : even;
}

// 6.42
using std::string;
inline string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

// 6.44 already inline
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
