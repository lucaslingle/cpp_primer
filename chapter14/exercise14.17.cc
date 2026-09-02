/*
Should the class you chose for exercise 7.40 define the equality operators?
If so implement them. If not why not?
*/

// yes it should. i will be defining a content-and-structure comparison though,
// not just content-only.

#include <iostream>
#include <string>
#include <memory>

class Tree {
friend std::ostream& operator<<(std::ostream&, const Tree&);
friend Tree operator+(const Tree&, const Tree&);
friend bool operator==(const Tree &lhs, const Tree &rhs);
friend bool operator!=(const Tree &lhs, const Tree &rhs);
private:
    std::string data;
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

bool operator==(const Tree &lhs, const Tree &rhs) {
    if (lhs.data != rhs.data)
        return false;

    if (static_cast<bool>(lhs.left) != static_cast<bool>(rhs.left))
        return false;

    if (static_cast<bool>(lhs.right) != static_cast<bool>(rhs.right))
        return false;

    if (lhs.left && !(*lhs.left == *rhs.left))
        return false;

    if (lhs.right && !(*lhs.right == *rhs.right))
        return false;
    
    return true;
}

bool operator!=(const Tree &lhs, const Tree &rhs) {
    return !(lhs == rhs);
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
