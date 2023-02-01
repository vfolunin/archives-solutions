class Solution {
    void rec(TreeNode *n, vector<int> &res) {
        if (!n)
            return;
        
        rec(n->left, res);
        rec(n->right, res);

        if (n->left && !n->right)
            res.push_back(n->left->val);
        if (!n->left && n->right)
            res.push_back(n->right->val);
    }

public:
    vector<int> getLonelyNodes(TreeNode *root) {
        vector<int> res;
        rec(root, res);
        return res;
    }
};