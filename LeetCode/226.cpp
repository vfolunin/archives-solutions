class Solution {
public:
    TreeNode *invertTree(TreeNode *n) {
        if (!n)
            return 0;
        swap(n->left, n->right);
        invertTree(n->left);
        invertTree(n->right);
        return n;
    }
};