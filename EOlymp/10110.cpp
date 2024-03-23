int maxDepth(TreeNode *n) {
    if (!n)
        return 0;

    int res = 1;
    if (n->left)
        res = max(res, maxDepth(n->left) + 1);
    if (n->right)
        res = max(res, maxDepth(n->right) + 1);
    return res;
}