class Solution {
    void rec(Node *n, Node *p) {
        if (!n)
            return;
        
        if (n->parent) {
            if (n->left)
                n->right = n->left;

            if (n->parent->left == n)
                n->parent->left = 0;
            else
                n->parent->right = 0;

            n->left = n->parent;

            rec(n->left, n);
        }

        n->parent = p;
    }

public:
    Node *flipBinaryTree(Node *root, Node *leaf) {
        rec(leaf, 0);
        return leaf;
    }
};