/*
Decide whether the class you used in exercise 7.40 needs a copy- and move-assignment operator.
If so, define those operators.
*/

// i think the Tree class for binary search trees would benefit from these operators.
// though this is definitely the wrong chapter for this exercise!

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
    Tree(const Tree &tree);
    Tree(Tree &&tree) noexcept;
    Tree& operator=(const Tree &tree);
    Tree& operator=(Tree &&tree) noexcept;
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
    Tree sum(rhs);
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

Tree::Tree(const Tree &tree):
    data(tree.data),
    left(tree.left ? std::unique_ptr<Tree>(new Tree(*tree.left)) : nullptr),
    right(tree.right ? std::unique_ptr<Tree>(new Tree(*tree.right)) : nullptr)
{

}


Tree::Tree(Tree &&tree) noexcept : 
    data(std::move(tree.data)), 
    left(std::move(tree.left)), 
    right(std::move(tree.right)) // moving a unique ptr nulls it.
{ 

}

Tree& Tree::operator=(const Tree &tree) {
    if (this == &tree)
        return *this;
    data = tree.data;
    left = tree.left ? std::unique_ptr<Tree>(new Tree(*tree.left)) : nullptr;
    right = tree.right ? std::unique_ptr<Tree>(new Tree(*tree.right)) : nullptr;
    return *this;
}

Tree& Tree::operator=(Tree &&tree) noexcept {
    if (this == &tree)
        return *this;
    data = std::move(tree.data);
    left = std::move(tree.left);
    right = std::move(tree.right);
    return *this;
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
