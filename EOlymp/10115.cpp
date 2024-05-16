bool isSymmetric(TreeNode *a, TreeNode *b) {
    if (!a || !b)
        return !a && !b;
    return a->val == b->val && isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left);
}

bool isSymmetric(TreeNode *n) {
    return !n || isSymmetric(n->left, n->right);
}