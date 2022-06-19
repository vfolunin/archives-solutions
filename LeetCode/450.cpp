class Solution {
    TreeNode *successor(TreeNode *n) {
        n = n->right;
        while (n->left)
            n = n->left;
        return n;
    }

    void remove(TreeNode *&n, int val) {
        if (!n)
            return;
        
        if (val == n->val) {
            if (!n->left || !n->right) {
                TreeNode *child = n->left ? n->left : n->right;
                delete n;
                n = child;
             } else {
                TreeNode *succ = successor(n);
                n->val = succ->val;
                remove(n->right, succ->val);
            }
            return;
        }
        
        remove(val < n->val ? n->left : n->right, val);
    }

public:
    TreeNode *deleteNode(TreeNode* root, int val) {
        remove(root, val);
        return root;
    }
};