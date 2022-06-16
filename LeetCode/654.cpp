class Solution {
    TreeNode *rec(vector<int> &a, int l, int r) {
        if (l > r)
            return 0;
        int m = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
        TreeNode *res = new TreeNode(a[m]);
        res->left = rec(a, l, m - 1);
        res->right = rec(a, m + 1, r);
        return res;
    }
    
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &a) {
        return rec(a, 0, a.size() - 1);
    }
};