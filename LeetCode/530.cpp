class Solution {
    struct Data {
        int minDiff, min, max;
    };
    
    Data rec(TreeNode *n) {
        Data res = { (int)1e9, n->val, n->val };
        if (n->left) {
            Data l = rec(n->left);
            res.min = l.min;
            res.minDiff = min(res.minDiff, min(l.minDiff, n->val - l.max));
        }
        if (n->right) {
            Data r = rec(n->right);
            res.max = r.max;
            res.minDiff = min(res.minDiff, min(r.minDiff, r.min - n->val));
        }
        return res;
    }
    
public:
    int getMinimumDifference(TreeNode *root) {
        return rec(root).minDiff;
    }
};