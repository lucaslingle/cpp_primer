/*
Define addition and subtraction for StrBlobPtr so that these operators
implement pointer arithmetic.
*/

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <cstddef>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::invalid_argument;
using std::runtime_error;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using size_type = vector<string>::size_type;
using std::ptrdiff_t;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    public:
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

        StrBlobPtr begin();
        StrBlobPtr end();

    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const {
            if (i >= data->size())
                throw out_of_range(msg);
        }
};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    friend StrBlobPtr operator+(const StrBlobPtr&, size_type);
    friend StrBlobPtr operator-(const StrBlobPtr&, size_type);
    friend ptrdiff_t operator-(const StrBlobPtr&, const StrBlobPtr&);
    public: 
        StrBlobPtr(): curr(0) { }
        StrBlobPtr(StrBlob &a, size_type sz = 0):
            wptr(a.data), curr(sz) { }
        string& deref() const;
        StrBlobPtr& incr();

        string& operator[](size_type ix) { 
            auto lock = check(curr+ix, "increment past end of StrBlobPtr");
            return (*lock)[curr+ix]; 
        }
        const string& operator[](size_type ix) const { 
            auto lock = check(curr+ix, "increment past end of StrBlobPtr");
            return (*lock)[curr+ix]; 
        }    

        StrBlobPtr& operator++() { 
            check(curr, "increment past end of StrBlobPtr");
            ++curr; 
            return *this; 
        }
        StrBlobPtr& operator--() { 
            check(curr-1, "decrement past beginning of StrBlobPtr");
            --curr; 
            return *this; 
        }
        StrBlobPtr operator++(int) { 
            auto ret = *this; 
            ++*this; 
            return ret; 
        }
        StrBlobPtr operator--(int) { 
            auto ret = *this; 
            --*this; 
            return ret; 
        }

        StrBlobPtr& operator+=(size_type offset) {
            check(curr+offset, "adding offset yields bad StrBlobPtr");
            curr += offset;
            return *this;
        }
        StrBlobPtr& operator-=(size_type offset) {
            check(curr-offset, "subtracting offset yields bad StrBlobPtr");
            curr -= offset;
            return *this;
        }

    private:
        shared_ptr<vector<string>> check(size_type, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_type curr;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_type i, const string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

inline bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw invalid_argument("operator== error: StrBlobPtrs should point to same StrBlob.");
    return (lhs.curr == rhs.curr);
}

inline bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs == rhs);
}

inline bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw invalid_argument("operator< error: StrBlobPtrs should point to same StrBlob.");
    return (lhs.curr < rhs.curr);
}

inline bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs > rhs);
}

inline bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return (rhs < lhs);
}

inline bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs < rhs);
}

StrBlobPtr operator+(const StrBlobPtr& sbp, size_type offset) {
    StrBlobPtr clone(sbp);
    clone += offset;
    return clone;
}

StrBlobPtr operator-(const StrBlobPtr& sbp, size_type offset) {
    StrBlobPtr clone(sbp);
    clone -= offset;
    return clone;
}

ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw invalid_argument("subtracted StrBlobPtrs must point to same StrBlob data.");
    return static_cast<ptrdiff_t>(lhs.curr) - static_cast<ptrdiff_t>(rhs.curr);
}