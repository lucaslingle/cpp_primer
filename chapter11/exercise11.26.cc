/*
What type can be used to subscript a map? 
What type does the subscript operator return?
Give a concrete example--that is, define a map and then write
the types that can be used to subscript the map 
and the type that would be returned from the subscript operator.
*/

// for a map of type map<K, V>, the type for a subscript is K, or map<K,V>::key_type.
// the subscript returns type V, or map<K,V>::mapped_type.
//
// for example a map<string, int> requires strings for subscripting,
// and returns ints from the subscripting operator:
// map<string, int> m = {{"Hello", 2}, {"World", 1}},
// m["Hello"] == 2
