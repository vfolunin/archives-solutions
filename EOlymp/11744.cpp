int sumOneSon(TreeNode *n) {
    if (!n)
        return 0;

    int res = sumOneSon(n->left) + sumOneSon(n->right);
    if (n->left && !n->right || !n->left && n->right)
        res += n->val;
    return res;
}