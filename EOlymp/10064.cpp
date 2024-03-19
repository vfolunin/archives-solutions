int Sum(TreeNode *n) {
    return n ? Sum(n->left) + n->val + Sum(n->right) : 0;
}