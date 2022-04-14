class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        int res = 1e9;
        if (root->left)
            res = min(res, minDepth(root->left) + 1);
        if (root->right)
            res = min(res, minDepth(root->right) + 1);
        return res;
    }
};