/*
Given the following classes, implement a default constructor and the
necessary copy-control members.

(a)
class TreeNode {
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
};

(b)
class BinStrTree {
    private:
        TreeNode *root;
}
*/

#include <string>
using std::string;

// (a)
class TreeNode {
    public:
        TreeNode(): value(string()), count(0), left(nullptr), right(nullptr) { }
        TreeNode(const string &value, int count, TreeNode *left, TreeNode *right):
            value(value), 
            count(count), 
            left(left ? (new TreeNode(*left)) : nullptr), 
            right(right ? (new TreeNode(*right)) : nullptr) { }
        TreeNode(const TreeNode &t):
            value(t.value), 
            count(t.count), 
            left(t.left ? (new TreeNode(*t.left)) : nullptr),
            right(t.right ? (new TreeNode(*t.right)) : nullptr) { }
        TreeNode& operator=(const TreeNode &rhs) {
            auto left_new = (rhs.left) ? (new TreeNode(*rhs.left)) : nullptr;
            auto right_new = (rhs.right) ? (new TreeNode(*rhs.right)) : nullptr;
            delete left;
            delete right;
            value = rhs.value;
            count = rhs.count;
            left = left_new;
            right = right_new;
            return *this;
        }
        ~TreeNode() {
            delete left;
            delete right;
        }
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
};

// (b)
class BinStrTree {
    public:
        BinStrTree(): root(nullptr) { }
        BinStrTree(TreeNode *root):
            root(root ? new TreeNode(*root) : nullptr) { }
        BinStrTree(const BinStrTree &b):
            root(b.root ? new TreeNode(*b.root) : nullptr) { }
        BinStrTree& operator=(const BinStrTree &rhs) {
            auto new_root = rhs.root ? new TreeNode(*rhs.root) : nullptr;
            delete root;
            root = new_root;
            return *this;
        }
        ~BinStrTree() {
            delete root;
        }
    private:
        TreeNode *root;
};
