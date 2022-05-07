class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0 };
        auto [lSum, lTiltSum] = rec(n->left);
        auto [rSum, rTiltSum] = rec(n->right);
        return { lSum + n->val + rSum, lTiltSum + abs(lSum - rSum) + rTiltSum };
    }
    
public:
    int findTilt(TreeNode *root) {
        return rec(root).second;
    }
};