class Solution {
public:
    Node *inorderSuccessor(Node *n) {
        if (n->right) {
            Node *res = n->right;
            while (res->left)
                res = res->left;
            return res;
        }

        while (n->parent) {
            if (n->parent->left == n)
                return n->parent;
            n = n->parent;
        }
        
        return 0;
    }
};