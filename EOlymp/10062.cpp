TreeNode *Maximum(TreeNode *n) {
    while (n->right)
        n = n->right;
    return n;
}