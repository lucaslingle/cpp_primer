/*
For the class you wrote for exercise 7.40 on p. 291, decide whether
any of the constructors might use delegation. If so, write the 
delegating constructors for your class. 
If not, look at the list of abstractions that you think would use a 
delegating constructor. Write the class definition for that abstraction.
*/

#include <iostream>
#include <string>

class Tree {
private:
    const std::string data;
    Tree *left = nullptr;
    Tree *right = nullptr;
public:
    Tree(const std::string s, Tree *l, Tree *r): 
        data(s), left(l), right(r) { }
    Tree(const std::string s): Tree(s, nullptr, nullptr) { }
    const std::string& get_data() { return this->data; }
    void add(const Tree *node) {
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
