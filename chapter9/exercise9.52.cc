/*
Use a stack to process parenthesized expressions.
When you see an open parenthesis, note that it was seen [by adding it to stack?]. 
When you see a close parenthesis after an open parenthesis, pop elements down to 
and including the open parenthesis off the stack.
Push a value onto the stack to indicate that a parenthesized expression was replaced. 
*/

#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string expression;
    std::stack<char> stck;

    std::getline(std::cin, expression);
    for (char c : expression) {
        std::cout << "got " << c << std::endl;
        if (c == '(')
            stck.push(c);
        if (c == ')') {
            while (stck.top() != '(') {
                std::cout << "stack top popped " << stck.top() << std::endl;
                stck.pop();
            }
            stck.pop();
            std::cout << "stack top pushed " << "*" << std::endl;
            stck.push('*');
        }
    }

    while (!stck.empty()) {
        std::cout << stck.top() << " ";
        stck.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
