#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>
using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::shared_ptr;
using std::make_shared;

class StrBlob {
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);
    public:
        typedef vector<string>::size_type size_type;

        StrBlob(): data(make_shared<vector<string>>()) { }
        StrBlob(initializer_list<string> il):
            data(make_shared<vector<string>>(il)) { }

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string &t) { data->push_back(t); }
        void pop_back() { 
            check(0, "pop_back cannot be applied on empty StrBlob");
            data->pop_back();
        }

        string& front() {
            check(0, "front cannot be applied on empty StrBlob");
            return data->front();
        }
        string& back() {
            check(0, "back cannot be applied on empty StrBlob");
            return data->back();
        }

        const string& front() const {
            check(0, "front cannot be applied on empty StrBlob");
            return data->front();
        }
        const string& back() const {
            check(0, "back cannot be applied on empty StrBlob");
            return data->back();
        }

        string& operator[](size_type ix) { return (*data)[ix]; }
        const string& operator[](size_type ix) const { return (*data)[ix]; }
    
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const {
            if (i >= data->size())
                throw out_of_range(msg);
        }
};

inline bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

inline bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

inline bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data < *rhs.data;
}

inline bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

inline bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return (rhs < lhs);
}

inline bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return (rhs <= lhs);
}
