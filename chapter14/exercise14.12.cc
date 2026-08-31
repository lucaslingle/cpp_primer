/*
Define an input operator for the class you used in exercise 7.40.
Be sure the operator handles input errors.
*/

#include <iostream>
#include <string>
#include <memory>

class Tree {
friend std::ostream& operator<<(std::ostream&, const Tree&);
private:
    const std::string data;
    std::unique_ptr<Tree> left = nullptr;
    std::unique_ptr<Tree> right = nullptr;
public:
    Tree(const std::string &s): data(s) { }
    void add(const std::string &s) {
        if (s <= data) {
            if (left)
                left->add(s);
            else
                left = std::unique_ptr<Tree>(new Tree(s));
        } else {
            if (right)
                right->add(s);
            else
                right = std::unique_ptr<Tree>(new Tree(s));
        }    
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
        tree.add(s);
    return ist;
}

int main() {
    Tree tree("monkey");
    tree.add("sloth");
    tree.add("lemur");
    tree.add("dog");
    tree.add("cat");

    while (std::cin >> tree)
        std::cout << tree << std::endl;

    return 0;
}
