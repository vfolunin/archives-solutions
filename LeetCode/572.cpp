class Solution {
    bool areEqual(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return 1;
        if (!a || !b)
            return 0;
        return a->val == b->val && areEqual(a->left, b->left) && areEqual(a->right, b->right);
    }
    
public:
    bool isSubtree(TreeNode *a, TreeNode *b) {
        if (!a)
            return 0;
        return areEqual(a, b) || isSubtree(a->left, b) || isSubtree(a->right, b);
    }
};