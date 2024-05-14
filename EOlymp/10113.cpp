int SumLeaves(TreeNode *n) {
    if (!n)
        return 0;
    if (!n->left && !n->right)
        return n->val;
    return SumLeaves(n->left) + SumLeaves(n->right);
}
