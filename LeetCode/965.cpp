class Solution {
    bool rec(TreeNode *n, int val) {
        return !n || n->val == val && rec(n->left, val) && rec(n->right, val);
    }
    
public:
    bool isUnivalTree(TreeNode *root) {
        return !root || rec(root, root->val);
    }
};