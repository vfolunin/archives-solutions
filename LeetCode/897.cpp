class Solution {
    void traverse(TreeNode *n, TreeNode *&list) {
        if (!n)
            return;
        traverse(n->left, list);
        list = list->right = new TreeNode(n->val);
        traverse(n->right, list);
    }
    
public:
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *list = new TreeNode(), *res = list;
        traverse(root, list);
        return res->right;
    }
};