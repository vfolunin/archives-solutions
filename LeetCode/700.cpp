class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root || val == root->val)
            return root;
        return searchBST(val < root->val ? root->left : root->right, val);
    }
};