class Solution {
public:
    void flatten(TreeNode *n) {
        if (!n)
            return;
        
        TreeNode *l = n->left, *r = n->right;
        flatten(l);
        flatten(r);
        
        n->left = 0;
        n->right = l;
        
        while (n->right)
            n = n->right;
        n->right = r;
    }
};