class Solution {
    bool rec(TreeNode *n, long long l, long long r) {
        if (!n)
            return 1;
        if (n->val < l || n->val > r)
            return 0;
        return rec(n->left, l, n->val - 1LL) && rec(n->right, n->val + 1LL, r);
    }
    
public:
    bool isValidBST(TreeNode *root) {
        return rec(root, -1e10, 1e10);
    }
};