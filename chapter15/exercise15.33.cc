/*
What happens when an object of type `Query_base` 
is copied, moved, assigned, or destroyed? 

reference code:
```
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
}
```
*/

// Abstract: An object of Query_base cannot be directly instantiated because
// it is an abstract base class (contains pure virtual functions).

// Copied: As a subobject of a derived class of Query_base, there is a synthesized
// copy constructor and synthesized copy assignment operator that could run.
// However, since Query_base has no data members, these do nothing. 

// Moved: The move constructor and move assignment operator are not defined, 
// since the destructor is explicitly declared in the class. Any attempt to move
// will fall back to the corresponding copy operation. 
// However, since Query_base has no data members, these do nothing. 

// Destroyed: the synthesized default destructor is run for Query_base;
// it is explicitly defined as the destructor for Query_base. Since the destructor is
// virtual, deleting a derived class through a pointer to a Query_base will 
// trigger a dynamically bound destructor, which will be the one for the derived class.
// At the end of derived class destructor's run, the base class destructor will run.