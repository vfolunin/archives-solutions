TreeNode *Minimum(TreeNode *n) {
    while (n->left)
        n = n->left;
    return n;
}