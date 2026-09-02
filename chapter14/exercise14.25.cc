/*
Implement any other assignment operators your class should define.
Explain which types should be used as operands and why.
*/

// the only remaining thing to do is to include constructors and assignments 
// for initializer_list<string>. everything else was done earlier.
// initializer_list would be used to provide a list of elements 
// without requiring the user to directly call successive insert operations.


#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>

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
    Tree() = default;
    Tree(const std::string &s): data(s) { }
    Tree(const Tree &tree);
    Tree(Tree &&tree) noexcept;
    Tree(std::initializer_list<std::string> il);
    Tree& operator=(const Tree &tree);
    Tree& operator=(Tree &&tree) noexcept;
    Tree& operator=(std::initializer_list<std::string> il);
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

Tree operator+(const Tree &lhs, const Tree &rhs) {
    Tree sum(lhs);
    sum += rhs;
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

Tree::Tree(std::initializer_list<std::string> il) {
    if (il.size() == 0) {
        data = ""; 
        return;
    }

    auto beg = il.begin();
    auto end = il.end();
    data = *beg++;
    while (beg != end)
        this->insert(*beg++);
}

Tree& Tree::operator=(std::initializer_list<std::string> il) {
    if (il.size() == 0) {
        data = ""; 
        left = nullptr;
        right = nullptr;
        return *this;
    }

    auto beg = il.begin();
    auto end = il.end();
    data = *beg++;
    left = nullptr;
    right = nullptr;
    while (beg != end)
        this->insert(*beg++);
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
