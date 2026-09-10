/*
For the expression built in Figure 15.3 (p. 638)
(a) List the constructors executed in processing that expression.
(b) List the calls to `rep` that are made from `cout << q`.
(c) List the calls to `eval` that are made from `q.eval()`.

reference expression
```
Query("fiery") & Query("bird") | Query("wind");
```
*/

// (a)
//
// Query_base constructor, default
// WordQuery constructor, string-based
// Query constructor, string-based
// Query_base constructor, default
// WordQuery constructor, string-based
// Query constructor, string-based
// Query_base constructor, default
// BinaryQuery constructor
// AndQuery constructor
// Query constructor, pointer-based
// Query_base constructor, default
// WordQuery constructor, string-based
// Query constructor, string-based
// Query_base constructor, default
// BinaryQuery constructor
// OrQuery constructor
// Query constructor, pointer-based

// (b) 
//
// Query::rep()
// BinaryQuery::rep()
// Query::rep()
// BinaryQuery::rep()
// Query::rep()
// WordQuery::rep()
// Query::rep()
// WordQuery::rep()
// Query::rep()
// WordQuery::rep()
//
// human "readable" version:
// operator<<(ostream &os, const Query &query) calls query.rep()
//
// For query.rep() it is a call to Query::rep()
// which calls q->rep() for data member `shared_ptr<Query_base> q`
// q->rep() is being applied to an OrQuery derived class of Query_base.
// OrQuery::rep() is inherited from BinaryQuery::rep(),
// which returns a parenthesized version of lhs.rep() | rhs.rep().
// 
// For lhs.rep(), it is a call to Query::rep()
// which calls q->rep() for data member `shared_ptr<Query_base> q`
// q->rep() applies to an AndQuery derived class of Query_base.
// AndQuery::rep() is inherited from BinaryQuery::rep(),
// which returns a parenthesized version of lhs2.rep() & rhs2.rep().
//
// For lhs2.rep(), it is a call to Query::rep()
// which calls q->rep() for data member `shared_ptr<Query_base> q`
// q->rep() applies to a WordQuery derived class of Query_base,
// which prints the word "fiery"
//
// For rhs2.rep(), it is a call to Query::rep()
// which calls q->rep() for data member `shared_ptr<Query_base> q`
// q->rep() applies to a WordQuery derived class of Query_base,
// which prints the word "bird"
//
// For rhs.rep(), it is a call to Query::rep()
// which calls q->rep() for data member `shared_ptr<Query_base> q`
// q->rep() applies to a WordQuery derived class of Query_base,
// which prints the word "wind"

// (c) 
//
// For q.eval() it is a call to Query::eval()
// which calls q->eval() for a data member `shared_ptr<Query_base> q`
// q->rep() is being applied to an OrQuery derived class of Query_base.
// OrQuery::rep() declared but not yet defined by OrQuery.
