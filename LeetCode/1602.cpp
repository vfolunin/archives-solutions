class Solution {
    void rec(TreeNode *n, int depth, TreeNode *target, int &targetDepth, TreeNode *&res) {
        if (!n)
            return;
        
        if (n == target)
            targetDepth = depth;
        else if (depth == targetDepth && !res)
            res = n;

        rec(n->left, depth + 1, target, targetDepth, res);
        rec(n->right, depth + 1, target, targetDepth, res);
    }

public:
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *target) {
        int targetDepth = -1;
        TreeNode *res = 0;
        rec(root, 0, target, targetDepth, res);
        return res;
    }
};