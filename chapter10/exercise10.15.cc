/*
Write a lambda that captures an int from its enclosing function and
takes an int parameter. The lambda should return the sum of the captured int
and the int parameter.
*/

[a](int b) -> int { return a + b; }
