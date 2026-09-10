/*
What happens when an object of type `Query` is 
copied, moved, assigned, or destroyed?

reference code:
```
class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    std::string rep() const {
        return q->rep();
    }
private:
    Query(std::shared_ptr<Query_base> query): q(query) { }
    std::shared_ptr<Query_base> q;
}
```
*/

// copied: the synthesized copy constructor is used.
// the only data member is a shared_ptr; it will be copied.

// moved: the synthesized move constructor is used.
// the only data member is a shared_ptr; it will be moved instead of copied.

// assigned: the synthesized assignment operator will be used.
// the only data member is a shared_ptr; it will be move-assigned or copy-assigned.

// destroyed: the synthesized destructor is used.
// the only data member is a shared_ptr; the bound object will be destroyed
// if the strong reference count reaches zero. 
