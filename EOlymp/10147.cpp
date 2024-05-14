TreeNode *Prev(TreeNode *n) {
    if (n->left) {
        n = n->left;
        while (n->right)
            n = n->right;
        return n;
    }
    while (n->parent) {
        if (n == n->parent->right)
            return n->parent;
        n = n->parent;
    }
    return 0;
}