/*
Write a version of `sum` with a return type that is guaranteed
to be large enough to hold the result of the addition.
*/

template <typename T1, typename T2>
auto sum(const T1& lhs, const T2& rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}
