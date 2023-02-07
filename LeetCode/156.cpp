class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *n, TreeNode *l = 0, TreeNode *r = 0) {
        if (!n)
            return 0;
        
        if (!n->left) {
            n->left = l;
            n->right = r;
            return n;
        }
        
        TreeNode *res = upsideDownBinaryTree(n->left, n->right, n);
        n->left = l;
        n->right = r;
        return res;
    }
};