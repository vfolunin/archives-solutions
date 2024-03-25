void PreOrder(TreeNode *n) {
    if (!n)
        return;
    
    cout << n->val << " ";
    PreOrder(n->left);
    PreOrder(n->right);
}
