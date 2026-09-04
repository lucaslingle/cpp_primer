/*
Add dereference and arrow operators to your `StrBlobPtr` class
and the `ConstStrBlobPtr` class you defined in exercise 12.22.
Note that the operators in `ConstStrBlobPtr` must return const references
because the `data` member in `ConstStrBlobPtr` points to a `const vector`.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::ifstream;
using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using size_type = vector<string>::size_type;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    public:
        friend class StrBlobPtr;
        friend class ConstStrBlobPtr;

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
        ConstStrBlobPtr begin() const;
        ConstStrBlobPtr end() const;
    
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
        //string& deref() const;
        string& operator*() const {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        string* operator->() const {
            return &(this->operator*());
        }
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

// string& StrBlobPtr::deref() const {
//     auto p = check(curr, "dereference past end");
//     return (*p)[curr];
// }

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

class ConstStrBlobPtr {
    public: 
        ConstStrBlobPtr(): curr(0) { }
        ConstStrBlobPtr(const StrBlob &a, size_type sz = 0):
            wptr(a.data), curr(sz) { }
        //const string& deref() const;
        const string& operator*() const {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        const string* operator->() const {
            return &(this->operator*());
        }
        ConstStrBlobPtr& incr();
    private:
        shared_ptr<const vector<string>> check(size_type, const string&) const;
        weak_ptr<const vector<string>> wptr;
        size_type curr;
};

shared_ptr<const vector<string>>
ConstStrBlobPtr::check(size_type i, const string& msg) const {
    const auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

// const string& ConstStrBlobPtr::deref() const {
//     const auto p = check(curr, "dereference past end");
//     return (*p)[curr];
// }

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const { return ConstStrBlobPtr(*this, data->size()); }

int main() {
    const StrBlob csb{"Hello", "World"};
    for (auto it = csb.begin(); ; it.incr()) {
        try {
            cout << *it << endl;
        } catch (const out_of_range&) {
            break;
        }
    }
    return 0;
}