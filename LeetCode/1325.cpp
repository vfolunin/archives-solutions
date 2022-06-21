class Solution {
public:
    TreeNode *removeLeafNodes(TreeNode *n, int target) {
        if (!n)
            return 0;
        
        n->left = removeLeafNodes(n->left, target);
        n->right = removeLeafNodes(n->right, target);
        
        if (n->val == target && !n->left && !n->right)
            return 0;
        
        return n;
    }
};