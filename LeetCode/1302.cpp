class Solution {
    void dfs(TreeNode *n, int depth, int &maxDepth, int &maxDepthSum) {
        if (!n)
            return;
        
        if (maxDepth < depth) {
            maxDepth = depth;
            maxDepthSum = n->val;
        } else if (maxDepth == depth) {
            maxDepthSum += n->val;
        }
        
        dfs(n->left, depth + 1, maxDepth, maxDepthSum);
        dfs(n->right, depth + 1, maxDepth, maxDepthSum);
    }
    
public:
    int deepestLeavesSum(TreeNode *root) {
        int maxDepth = 0, maxDepthSum = 0;
        dfs(root, 0, maxDepth, maxDepthSum);
        return maxDepthSum;
    }
};