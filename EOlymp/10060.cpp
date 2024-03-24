void PostOrder(TreeNode *n) {
    if (!n)
        return;
    
    PostOrder(n->left);
    PostOrder(n->right);
    cout << n->val << " ";
}