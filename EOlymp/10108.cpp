bool isSame(TreeNode *a, TreeNode *b) {
    if (!a || !b)
        return !a && !b;
    return a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
}