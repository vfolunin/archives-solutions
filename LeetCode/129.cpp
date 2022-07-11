class Solution {
    void rec(TreeNode *n, long long val, long long &res) {
        if (!n)
            return;
        
        val = val * 10 + n->val;
        
        if (!n->left && !n->right) {
            res += val;
            return;
        }
        
        rec(n->left, val, res);
        rec(n->right, val, res);
    }
    
public:
    int sumNumbers(TreeNode *root) {
        long long res = 0;
        rec(root, 0, res);
        return res;
    }
};