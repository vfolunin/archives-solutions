class Solution {
public:
    int goodNodes(TreeNode *n, int maxOnPath = -1e9) {
        if (!n)
            return 0;
        
        int res = n->val >= maxOnPath;
        res += goodNodes(n->left, max(maxOnPath, n->val));
        res += goodNodes(n->right, max(maxOnPath, n->val));
        
        return res;
    }
};