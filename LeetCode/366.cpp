class Solution {
    int rec(TreeNode *n, vector<vector<int>> &res) {
        if (!n)
            return -1;
        
        int lHeight = rec(n->left, res);
        int rHeight = rec(n->right, res);
        int height = max(lHeight, rHeight) + 1;

        if (res.size() <= height)
            res.resize(height + 1);
        res[height].push_back(n->val);

        return height;
    }

public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> res;
        rec(root, res);
        return res;
    }
};