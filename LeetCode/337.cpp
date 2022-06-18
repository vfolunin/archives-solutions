class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0 };
        auto [l0, l1] = rec(n->left);
        auto [r0, r1] = rec(n->right);
        return { max(l0, l1) + max(r0, r1), n->val + l0 + r0 };
    }
    
public:
    int rob(TreeNode *root) {
        auto [k0, k1] = rec(root);
        return max(k0, k1);
    }
};