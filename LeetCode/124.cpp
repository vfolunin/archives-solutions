class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { -1e9, -1e9 };
        
        auto [lMax, lBranch] = rec(n->left);
        auto [rMax, rBranch] = rec(n->right);
        
        return {
            max({ lMax, rMax, max(lBranch, 0) + n->val + max(rBranch, 0) }),
            max({ lBranch, rBranch, 0 }) + n->val
        };
    }
    
public:
    int maxPathSum(TreeNode* root) {
        return rec(root).first;
    }
};