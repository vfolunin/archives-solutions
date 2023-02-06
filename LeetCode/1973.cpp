class Solution {
    long long rec(TreeNode *n, int &res) {
        if (!n)
            return 0;
        
        long long lSum = rec(n->left, res);
        long long rSum = rec(n->right, res);
        res += lSum + rSum == n->val;

        return lSum + rSum + n->val;
    }

public:
    int equalToDescendants(TreeNode *root) {
        int res = 0;
        rec(root, res);
        return res;
    }
};