TreeNode *Invert(TreeNode *n) {
    if (n) {
        TreeNode *right = Invert(n->left);
        n->left = Invert(n->right);
        n->right = right;
    }
    return n;
}