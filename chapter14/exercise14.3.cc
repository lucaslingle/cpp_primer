/*
Both `string` and `vector` define an overloaded `==` that can be used
to compare objects of those types. Assuming `svec1` and `svec2` are `vectors`
that held `string`s, identify which version of `==` is applied 
in each of the following expressions:
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) "svec[0] == "stone"
*/

// (a) string equality
// (b) string equality
// (c) vector equality, which for vector<string> applies elementwise string equality
// (d) there are three unescaped double quotes here, it isn't a valid C++ expression
