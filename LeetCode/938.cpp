class Solution {
public:
    int rangeSumBST(TreeNode *n, int l, int r) {
        if (!n)
            return 0;
        
        int res = 0;
        if (l <= n->val && n->val <= r)
            res += n->val;
        
        if (l < n->val)
            res += rangeSumBST(n->left, l, r);
        if (n->val < r)
            res += rangeSumBST(n->right, l, r);
        
        return res;
    }
};