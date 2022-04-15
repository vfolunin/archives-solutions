class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root)
            return 0;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (high < root->val)
            return trimBST(root->left, low, high);
        return new TreeNode(root->val, trimBST(root->left, low, high), trimBST(root->right, low, high));
    }
};