/*
The following definition of `List` is incorrect. How would you fix it?
```
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};
```
*/

// Inside the scope of a class template, one should omit the angle brackets 
// on the class name because the class name `List<elemType>` 
// is injected in place of the template name `List`.

// On the other hand, the compiler has no way of knowing that the ListItem
// class template used by List should have the same template argument, so
// we have to supply that manually.

// The names front and end are usually front/back, or begin/end.
// I will leave that alone though since it's just a name. 

// The code becomes:

template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List();
    List(const List &);
    List& operator=(const List &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};