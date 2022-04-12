class Solution {
    bool areSymmetric(TreeNode *a, TreeNode *b) {
        if (!a || !b)
            return !a && !b;
        return a->val == b->val && areSymmetric(a->left, b->right) && areSymmetric(a->right, b->left);
    }
    
public:
    bool isSymmetric(TreeNode *root) {
        return areSymmetric(root->left, root->right);
    }
};