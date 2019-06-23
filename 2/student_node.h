#include "student.h"
class Node: public student
{
    private:
    student d;
    Node* left;
    Node* right;
    public:
        Node* first (student d);
        Node* search_insert (Node* root, student d);
        void print_tree (Node* p, int level);
        Node* goto_left (Node* root) {if (root->left) { root=root->left; return root;} return 0;}
        Node* goto_right (Node* root) {if (root->right){root=root->right; return root;} return 0;}
        const char* name () const { return d.get_name();}
        int value () const { return d.get_value();}
};
