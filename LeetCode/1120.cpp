class Solution {
    pair<double, double> rec(TreeNode *n, double &res) {
        if (!n)
            return { 0, 0 };
        
        auto [lNum, lDen] = rec(n->left, res);
        auto [rNum, rDen] = rec(n->right, res);
        
        double num = lNum + n->val + rNum;
        double den = lDen + 1 + rDen;
        res = max(res, num / den);

        return { num, den };
    }

public:
    double maximumAverageSubtree(TreeNode *root) {
        double res = 0;
        rec(root, res);
        return res;
    }
};