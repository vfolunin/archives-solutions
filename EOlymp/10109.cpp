int minDepth(TreeNode *n) {
    if (!n)
        return 0;

    int res = 1e9;
    if (n->left)
        res = min(res, minDepth(n->left) + 1);
    if (n->right)
        res = min(res, minDepth(n->right) + 1);
    return res != 1e9 ? res : 1;
}