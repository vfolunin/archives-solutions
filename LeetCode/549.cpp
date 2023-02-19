class Solution {
    pair<int, int> rec(TreeNode *n, int &res) {
        if (!n)
            return { 0, 0 };

        auto [lInc, lDec] = rec(n->left, res);
        auto [rInc, rDec] = rec(n->right, res);

        if ((!n->left || n->left->val + 1 == n->val) && (!n->right || n->val + 1 == n->right->val))
            res = max(res, lDec + 1 + rInc);
        if ((!n->left || n->left->val - 1 == n->val) && (!n->right || n->val - 1 == n->right->val))
            res = max(res, lInc + 1 + rDec);

        int inc = 1, dec = 1;
        if (n->left) {
            if (n->left->val + 1 == n->val)
                dec = max(dec, lDec + 1);
            if (n->left->val - 1 == n->val)
                inc = max(inc, lInc + 1);
        }
        if (n->right) {
            if (n->right->val + 1 == n->val)
                dec = max(dec, rDec + 1);
            if (n->right->val - 1 == n->val)
                inc = max(inc, rInc + 1);
        }
        res = max({ res, inc, dec });
        return { inc, dec };
    }

public:
    int longestConsecutive(TreeNode *root) {
        int res = 0;
        rec(root, res);
        return res;
    }
};