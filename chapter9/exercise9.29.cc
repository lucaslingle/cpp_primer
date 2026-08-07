/*
Given that vec holds 25 elements, what does vec.resize(100) do?
What if we next wrote vec.resize(10)?
*/

// since vec has size 25,
// vec.resize(100) adds 75 value-initialized elements to the end of vec.
// since the resized vec has size 100,
// vec.resize(10) removes the last 90 elements of vec.
