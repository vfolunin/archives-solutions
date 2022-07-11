class Solution {
    void traverse(TreeNode *n, int depth, vector<vector<int>> &res) {
        if (!n)
            return;
        
        if (res.size() == depth)
            res.emplace_back();
        res[depth].push_back(n->val);
        
        traverse(n->left, depth + 1, res);
        traverse(n->right, depth + 1, res);
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        traverse(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};