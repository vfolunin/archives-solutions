class Solution {
public:
    TreeNode *insertIntoMaxTree(TreeNode *n, int val) {
        if (!n)
            return new TreeNode(val);
        
        if (n->val < val)
            return new TreeNode(val, n, 0);
        
        n->right = insertIntoMaxTree(n->right, val);
        return n;
    }
};