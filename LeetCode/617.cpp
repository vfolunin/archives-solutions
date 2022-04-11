class Solution {
public:
    TreeNode *mergeTrees(TreeNode *a, TreeNode *b) {
        if (!a || !b)
            return a ? a : b;
        return new TreeNode(a->val + b->val, mergeTrees(a->left, b->left), mergeTrees(a->right, b->right));
    }
};