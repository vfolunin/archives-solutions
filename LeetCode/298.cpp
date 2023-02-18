class Solution {
    void rec(TreeNode *n, int cur, int &res) {
        if (!n)
            return;

        res = max(res, cur);

        rec(n->left, n->left && n->val + 1 == n->left->val ? cur + 1 : 1, res);
        rec(n->right, n->right && n->val + 1 == n->right->val ? cur + 1 : 1, res);
    }

public:
    int longestConsecutive(TreeNode *root) {
        int res = 0;
        rec(root, 1, res);
        return res;
    }
};