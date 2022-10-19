class Solution {
    void rec(TreeNode *n,
             unordered_map<TreeNode *, int> &l, unordered_map<TreeNode *, int> &r,
             unordered_map<TreeNode *, int> &sum, unordered_set<TreeNode *> &isBst) {
        if (!n)
            return;
        
        rec(n->left, l, r, sum, isBst);
        rec(n->right, l, r, sum, isBst);
        
        l[n] = min(n->val, l[n->left]);
        r[n] = max(n->val, r[n->right]);
        sum[n] = sum[n->left] + n->val + sum[n->right];
        
        if (r[n->left] < n->val && n->val < l[n->right] && isBst.count(n->left) && isBst.count(n->right))
            isBst.insert(n);      
    }
    
public:
    int maxSumBST(TreeNode *root) {
        unordered_map<TreeNode *, int> l = { { 0, 1e9 } };
        unordered_map<TreeNode *, int> r = { { 0, -1e9 } };
        unordered_map<TreeNode *, int> sum = { { 0, 0 } };
        unordered_set<TreeNode *> isBst = { 0 };
        rec(root, l, r, sum, isBst);
        
        int res = 0;
        for (TreeNode *n : isBst)
            res = max(res, sum[n]);
        return res;
    }
};