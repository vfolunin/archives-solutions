class Solution {
    inline static const long long MOD = 1e9 + 7;
    
    long long rec(TreeNode *n, long long totalSum, long long &res) {
        if (!n)
            return 0;
        
        long long sum = rec(n->left, totalSum, res) + n->val + rec(n->right, totalSum, res);
        
        if (totalSum)
            res = max(res, sum * (totalSum - sum));
        
        return sum;
    }
    
public:
    int maxProduct(TreeNode *root) {
        long long res = 0;
        rec(root, rec(root, 0, res), res);
        return res % MOD;
    }
};