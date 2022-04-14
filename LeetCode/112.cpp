class Solution {
    bool dfs(TreeNode *n, int sum, int targetSum) {
        sum += n->val;
        if (!n->left && !n->right)
            return sum == targetSum;
        return n->left && dfs(n->left, sum, targetSum) ||
               n->right && dfs(n->right, sum, targetSum);
    }
    
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        return root && dfs(root, 0, targetSum);
    }
};