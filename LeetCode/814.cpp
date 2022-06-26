class Solution {
    int rec(TreeNode *n) {
        if (!n)
            return 0;
        
        int l = rec(n->left);
        if (!l)
            n->left = 0;
        
        int r = rec(n->right);
        if (!r)
            n->right = 0;
        
        return l + (n->val == 1) + r;
    }
    
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!rec(root))
            root = 0;
        return root;
    }
};