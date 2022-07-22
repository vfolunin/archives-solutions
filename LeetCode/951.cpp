class Solution {
public:
    bool flipEquiv(TreeNode *a, TreeNode *b) {
        if (!a || !b)
            return !a && !b;
        
        if (a->val != b->val)
            return 0;
        
        if (a->left && (!a->right || a->left->val > a->right->val))
            swap(a->left, a->right);
        if (b->left && (!b->right || b->left->val > b->right->val))
            swap(b->left, b->right);
        
        return flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right);
    }
};