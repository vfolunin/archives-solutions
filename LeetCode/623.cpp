class Solution {
public:
    TreeNode *addOneRow(TreeNode *n, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, n, 0);
        
        if (!n)
            return n;
        
        if (depth == 2) {
            n->left = new TreeNode(val, n->left, 0);
            n->right = new TreeNode(val, 0, n->right);
            return n;
        }
        
        addOneRow(n->left, val, depth - 1);
        addOneRow(n->right, val, depth - 1);
        return n;
    }
};