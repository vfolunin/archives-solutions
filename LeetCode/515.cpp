class Solution {
    void rec(TreeNode *n, int depth, vector<int> &res) {
        if (!n)
            return;
        
        if (depth == res.size())
            res.push_back(n->val);
        else
            res[depth] = max(res[depth], n->val);
        
        rec(n->left, depth + 1, res);
        rec(n->right, depth + 1, res);
    }
    
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        rec(root, 0, res);
        return res;
    }
};