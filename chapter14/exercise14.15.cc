/*
Should the class you chose for exercise 7.40 define any arithmetic operators.
If so, implement them. If not, explain why not.
*/

// add two binary search trees together by combining elements.

#include <iostream>
#include <string>
#include <memory>

class Tree {
friend std::ostream& operator<<(std::ostream&, const Tree&);
friend Tree operator+(const Tree&, const Tree&);
private:
    const std::string data;
    std::unique_ptr<Tree> left = nullptr;
    std::unique_ptr<Tree> right = nullptr;
public:
    Tree(const std::string &s): data(s) { }
    void insert(const std::string &s) {
        if (s <= data) {
            if (left)
                left->insert(s);
            else
                left = std::unique_ptr<Tree>(new Tree(s));
        } else {
            if (right)
                right->insert(s);
            else
                right = std::unique_ptr<Tree>(new Tree(s));
        }    
    }
    Tree& operator+=(const Tree &tree) {
        insert(tree.data);
        if (tree.left)
            *this += *tree.left;
        if (tree.right)
            *this += *tree.right;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& ost, const Tree &tree) {
    if (tree.left)
        ost << *tree.left;
    ost << tree.data << " ";
    if (tree.right)
        ost << *tree.right;
    return ost;
}

std::istream& operator>>(std::istream& ist, Tree &tree) {
    std::string s;
    if (ist >> s)
        tree.insert(s);
    return ist;
}

Tree operator+(const Tree &rhs, const Tree &lhs) {
    // unique ptrs make copy constructor implicitly deleted
    // so cant do the usual pattern for bumming off operator+=
    // but we can with a slight adjustment
    Tree sum(rhs.data);
    if (rhs.left)
        sum += *rhs.left;
    if (rhs.right)
        sum += *rhs.right;
    sum += lhs;
    return sum;
}

int main() {
    Tree tree1("monkey");
    tree1.insert("sloth");

    Tree tree2("lemur");
    tree2.insert("dog");
    tree2.insert("cat");

    Tree tree3 = tree1 + tree2;
    tree2 += tree1;

    std::cout << tree3 << std::endl;
    std::cout << tree2 << std::endl;
    return 0;
}
