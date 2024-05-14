TreeNode *Next(TreeNode *n) {
    if (n->right) {
        n = n->right;
        while (n->left)
            n = n->left;
        return n;
    }
    while (n->parent) {
        if (n == n->parent->left)
            return n->parent;
        n = n->parent;
    }
    return 0;
}