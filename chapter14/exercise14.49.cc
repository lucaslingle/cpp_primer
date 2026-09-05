/*
Regardless of whether it is a good idea to do so, 
define a conversion to bool for the class from the previous exercise.
*/

// I refactored the original Tree class out into Node and Tree, 
// and added the conversion operator bool to the Tree class.

#include <iostream>
#include <string>
#include <memory>

class Node {
friend std::ostream& operator<<(std::ostream&, const Node&);
private:
    std::string data;
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;
public:
    Node(const std::string &s): data(s) { }
    Node(const Node &node);
    Node(Node &&node) noexcept;
    Node& operator=(const Node &node);
    Node& operator=(Node &&node) noexcept;
    void insert(const std::string &s) {
        if (s <= data) {
            if (left)
                left->insert(s);
            else
                left = std::unique_ptr<Node>(new Node(s));
        } else {
            if (right)
                right->insert(s);
            else
                right = std::unique_ptr<Node>(new Node(s));
        }    
    }
};

Node::Node(const Node &node):
    data(node.data),
    left(node.left ? std::unique_ptr<Node>(new Node(*node.left)) : nullptr),
    right(node.right ? std::unique_ptr<Node>(new Node(*node.right)) : nullptr)
{
}

Node::Node(Node &&node) noexcept : 
    data(std::move(node.data)), 
    left(std::move(node.left)), 
    right(std::move(node.right)) // unique_ptr move assignment operator nulls rhs
{ 
}

Node& Node::operator=(const Node &node) {
    if (this == &node)
        return *this;
    data = node.data;
    left = node.left ? std::unique_ptr<Node>(new Node(*node.left)) : nullptr;
    right = node.right ? std::unique_ptr<Node>(new Node(*node.right)) : nullptr;
    return *this;
}

Node& Node::operator=(Node &&node) noexcept {
    if (this == &node)
        return *this;
    data = std::move(node.data);
    left = std::move(node.left);
    right = std::move(node.right);
    return *this;
}

std::ostream& operator<<(std::ostream& ost, const Node &node) {
    if (node.left)
        ost << *node.left;
    ost << node.data << " ";
    if (node.right)
        ost << *node.right;
    return ost;
}

class Tree {
friend std::ostream& operator<<(std::ostream&, const Tree&);
private:
    std::unique_ptr<Node> root = nullptr;
public:
    Tree() = default;
    Tree(const Tree &tree);
    Tree(Tree &&tree) noexcept;
    Tree& operator=(const Tree &tree);
    Tree& operator=(Tree &&tree) noexcept;
    explicit operator bool() const { return static_cast<bool>(root); }
    void insert(const std::string &s) {
        if (root)
            root->insert(s);
        else
            root = std::unique_ptr<Node>(new Node(s));
    }
};

Tree::Tree(const Tree &tree):
    root(tree.root ? std::unique_ptr<Node>(new Node(*tree.root)) : nullptr)
{
}

Tree::Tree(Tree &&tree) noexcept : 
    root(std::move(tree.root)) // unique_ptr move assignment operator nulls rhs
{ 
}

Tree& Tree::operator=(const Tree &tree) {
    if (this == &tree)
        return *this;
    root = tree.root ? std::unique_ptr<Node>(new Node(*tree.root)) : nullptr;
    return *this;
}

Tree& Tree::operator=(Tree &&tree) noexcept {
    if (this == &tree)
        return *this;
    root = std::move(tree.root); // unique_ptr move assignment operator nulls rhs
    return *this;
}

std::ostream& operator<<(std::ostream& ost, const Tree &tree) {
    if (tree.root)
        ost << *tree.root;
    return ost;
}

int main() {
    Tree tree1;
    tree1.insert("monkey");
    tree1.insert("sloth");
    tree1.insert("lemur");
    tree1.insert("dog");
    tree1.insert("cat");

    std::cout << tree1 << std::endl;
    return 0;
}
