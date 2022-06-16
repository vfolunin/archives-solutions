class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *&n, int val) {
        if (!n)
            return n = new TreeNode(val);
        insertIntoBST(val < n->val ? n->left : n->right, val);
        return n;
    }
};