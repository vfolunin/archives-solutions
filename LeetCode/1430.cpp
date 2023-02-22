class Solution {
    bool rec(TreeNode *n, vector<int> &a, int i) {
        if (!n || a[i] != n->val)
            return 0;
        
        if (i + 1 == a.size())
            return !n->left && !n->right;
        
        return rec(n->left, a, i + 1) || rec(n->right, a, i + 1);
    }

public:
    bool isValidSequence(TreeNode *root, vector<int> &a) {
        return rec(root, a, 0);
    }
};