class Solution {
public:
    bool isSameTree(TreeNode *a, TreeNode *b) {
        if (!a || !b)
            return !a && !b;
        return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};