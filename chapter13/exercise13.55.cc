/*
Add an rvalue reference version of `push_back` to your `StrBlob`.
*/

#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <cstddef>

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::out_of_range;
using std::runtime_error;
using size_type = vector<string>::size_type;

class StrBlobPtr;

class StrBlob {
    public:
        friend class StrBlobPtr;

        StrBlob(): data(make_shared<vector<string>>()) { }
        StrBlob(initializer_list<string> il):
            data(make_shared<vector<string>>(il)) { }
        StrBlob(const StrBlob &blob): 
            data(make_shared<vector<string>>(*blob.data)) { }  
        // ^ make_shared will call copy constructor of vector<string>
        StrBlob& operator=(const StrBlob &rhs) {
            auto p = make_shared<vector<string>>(*rhs.data);
            data = p;
            return *this;
        }
        // ^ make_shared will call copy constructor of vector<string>

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string &t) { data->push_back(t); }
        void push_back(string &&t) { data->push_back(t); }
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
    public: 
        StrBlobPtr(): curr(0) { }
        StrBlobPtr(StrBlob &a, size_type sz = 0):
            wptr(a.data), curr(sz) { }
        string& deref() const;
        StrBlobPtr& incr();
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
