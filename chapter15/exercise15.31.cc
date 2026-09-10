/*
Given that s1, s2, s3 and s4 are all strings, determine what objects are 
created in the following expressions:
```
(a) Query(s1) | Query(s2) & ~ Query(s3);
(b) Query(s1) | (Query(s2) & ~ Query(s3));
(c) (Query(s1) & Query(s2)) | (Query(s3) & Query(s4));
```
*/

// (a) First of all, bitwise AND has a higher precedence that bitwise OR,
// and this precedence is retained for overloaded operators 
// like operator& and operator|.
//
// each expression Query(s) creates a `Query` object, which contains 
// a pointer to a `Query_base` object. In particular, it will be a pointer to
// the `Query_base`-derived class `WordQuery`. 
//
// The ~ expression will create a new `Query` object pointing to a `Query_base` object.
// In particular, it will be a pointer to the `Query_base`-derived class `NotQuery`.
//
// The & expression is next in precedence (before |) and creates a new `Query` object
// pointing to a `Query_base` object. In particular, it will be a pointer to the
// `Query_base`-derived class `AndQuery`.
//
// The | expression is next in precedence and creates a new `Query` object
// pointing to a `Query_base` object. In particular, it will be a pointer to the
// `Query_base`-derived class `OrQuery`.

// (b) Is exactly the same as (a), because the parentheses group the AND operation
// ahead of the OR operation, which is exactly the same as the precedence 
// of the overloaded operators `operator&` and `operator|`.

// (c) First creates four `Query` objects, each bound (pointing to) a `WordQuery`.
// The & expressions each create one more `Query` object, each bound to an `AndQuery`.
// The | expression creates one more `Query` object, bound to an `OrQuery`. 
