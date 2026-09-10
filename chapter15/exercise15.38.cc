/*
Are the following declarations legal? If not why not? 
If so explain what the declarations mean.
```
BinaryQuery a = Query("fiery") & Query("bird");
AndQuery b = Query("fiery") & Query("bird");
OrQuery c = Query("fiery") & Query("bird");
```
*/

// BinaryQuery is an abstract class and cannot be instantiated.
// In addition, the expression `Query("fiery") & Query("bird")`
// is of type Query, and there is no constructor of BinaryQuery to permit 
// an implicit conversion from type Query.

// The expression `Query("fiery") & Query("bird")`
// is of type Query, and there is no constructor of AndQuery to permit 
// an implicit conversion from type Query.

// The expression `Query("fiery") & Query("bird")`
// is of type Query, and there is no constructor of OrQuery to permit 
// an implicit conversion from type Query.
