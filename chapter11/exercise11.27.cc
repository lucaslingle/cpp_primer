/*
What kinds of problems would you use count to solve?
When might you use find instead?
*/

// for a map, count can be used to 
// indicate if an element is present without adding it (like subscript would).
// for a multimap, count can be used to
// count the number of records with a given key.

// for a map and a multimap, find returns an iterator to first element with a given key,
// which allows one to process the records themselves, starting at a given position.
// it thus allows access to the mapped type, which count does not grant access to.
