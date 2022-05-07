class Solution {    
public:
    TreeNode *lowestCommonAncestor(TreeNode *n, TreeNode *a, TreeNode *b) {
        if (a->val < n->val && b->val < n->val)
            return lowestCommonAncestor(n->left, a, b);
        if (a->val > n->val && b->val > n->val)
            return lowestCommonAncestor(n->right, a, b);
        return n;
    }
};