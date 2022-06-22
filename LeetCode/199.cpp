class Solution {
    void rec(TreeNode *n, int depth, vector<int> &res) {
        if (!n)
            return;
        
        if (depth == res.size())
            res.push_back(n->val);
        
        rec(n->right, depth + 1, res);
        rec(n->left, depth + 1, res);
    }
    
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        rec(root, 0, res);
        return res;
    }
};