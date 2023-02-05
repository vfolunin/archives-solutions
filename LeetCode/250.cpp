class Solution {
    pair<int, int> rec(TreeNode *n, int &res) {
        if (!n)
            return { 1e9, -1e9 };
        
        auto [lMin, lMax] = rec(n->left, res);
        auto [rMin, rMax] = rec(n->right, res);

        int tMin = min({ lMin, n->val, rMin });
        int tMax = max({ lMax, n->val, rMax });
        res += tMin == tMax;

        return { tMin, tMax };
    }

public:
    int countUnivalSubtrees(TreeNode *root) {
        int res = 0;
        rec(root, res);
        return res;
    }
};