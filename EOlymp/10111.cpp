int sumLeft(TreeNode *n) {
    if (!n)
        return 0;

    int res = 0;
    if (n->left && !n->left->left && !n->left->right)
        res += n->left->val;

    res += sumLeft(n->left);
    res += sumLeft(n->right);
    return res;
}