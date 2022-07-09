class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0 };
        
        auto [lDelta, lOps] = rec(n->left);
        auto [rDelta, rOps] = rec(n->right);
        
        int delta = n->val - 1 + lDelta + rDelta;
        int ops = lOps + rOps + abs(delta);
        
        return { delta, ops };
    }
    
public:
    int distributeCoins(TreeNode *root) {
        return rec(root).second;
    }
};