class Solution {
    int dfs(TreeNode *n) {
        if (!n)
            return 0;
        
        int res = dfs(n->left) + dfs(n->right);
        if (n->left && !n->left->left && !n->left->right)
            res += n->left->val;
        
        return res;
    }
    
public:
    int sumOfLeftLeaves(TreeNode *root) {
        return dfs(root);
    }
};