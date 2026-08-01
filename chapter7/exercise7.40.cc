/*
Choose one of the following abstractions (or one of your own choosing):
Book, Date, Employee, Vehicle, Object, Tree

Determine what data are needed in the class.
Provide an appropriate set of constructors. 
Explain your decisions.
*/

// explanation: im building a binary search tree. basic methods only.
#include <iostream>
#include <string>

class Tree {
private:
    std::string data;
    Tree *left = nullptr;
    Tree *right = nullptr;
public:
    Tree(std::string s): data(s) { }
    const std::string& get_data() { return this->data; }
    void add(Tree *node) {
        if (node->get_data() <= this->data) {
            if (this->left)
                this->left->add(node);
            else
                this->left = node;    
            return;
        }
        if (node->get_data() > this->data) {
            if (this->right)
                this->right->add(node);
            else
                this->right = node;   
            return;
        }    
    }
    std::ostream& print(std::ostream& ost) {
        if (this->left)
            this->left->print(ost);
        ost << (this->data) << " ";
        if (this->right)
            this->right->print(ost);
        return ost;
    }
};

int main() {
    Tree monkey = Tree("monkey");
    Tree sloth = Tree("sloth");
    Tree lemur = Tree("lemur");
    Tree dog = Tree("dog");
    Tree cat = Tree("cat");

    Tree tree = monkey;
    tree.add(&sloth);
    tree.add(&lemur);
    tree.add(&dog);
    tree.add(&cat);

    tree.print(std::cout) << std::endl;

    return 0;
}
