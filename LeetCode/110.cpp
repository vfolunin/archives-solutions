class Solution {
    pair<bool, int> check(TreeNode *n) {
        if (!n)
            return { 1, 0 };
        auto [lBalanced, lHeight] = check(n->left);
        auto [rBalanced, rHeight] = check(n->right);
        return { lBalanced && rBalanced && abs(lHeight - rHeight) <= 1, 1 + max(lHeight, rHeight) };
    }
    
public:
    bool isBalanced(TreeNode *root) {
        return check(root).first;
    }
};