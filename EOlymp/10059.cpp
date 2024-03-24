void InOrder(TreeNode *n) {
    if (!n)
        return;
    
    InOrder(n->left);
    cout << n->val << " ";
    InOrder(n->right);
}
