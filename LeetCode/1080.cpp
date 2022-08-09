class Solution {
    int rec(TreeNode *&n, int sum, int limit) {
        if (!n)
            return -2e9;
        
        sum += n->val;
        
        if (!n->left && !n->right) {
            if (sum >= limit)
                return sum;
            n = 0;
            return -2e9;
        }
        
        int maxSum = max(rec(n->left, sum, limit), rec(n->right, sum, limit));
        if (maxSum >= limit)
            return maxSum;
        n = 0;
        return -2e9;
    }
    
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        rec(root, 0, limit);
        return root;
    }
};