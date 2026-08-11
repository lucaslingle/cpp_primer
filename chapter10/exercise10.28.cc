/*
Copy a vector that holds values from 1 to 9 inclusive, into three
other containers. Use an inserter, a back_inserter, and a front_inserter, 
respectively to add elements to these containers. Predict how the output
sequence varies by the kind of inserter and verify your predictions 
by running your programs.
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

int main() {
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> lst;
    std::deque<int> dq;
    std::forward_list<int> fl;

    std::copy(ivec.begin(), ivec.end(), std::inserter(lst, lst.end())); // keeps order
    std::copy(ivec.begin(), ivec.end(), std::back_inserter(dq));  // keeps order
    std::copy(ivec.begin(), ivec.end(), std::front_inserter(fl)); // reverses

    std::for_each(lst.begin(), lst.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    std::for_each(dq.begin(), dq.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    std::for_each(fl.begin(), fl.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}
