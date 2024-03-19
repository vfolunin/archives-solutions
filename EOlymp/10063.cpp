TreeNode *Find(TreeNode *n, int value) {
    if (!n || n->val == value)
        return n;
    return Find(value < n->val ? n->left : n->right, value);
}
