class Solution {
    void rec(TreeNode *n, int depth, vector<int> &res) {
        if (!n)
            return;
        
        if (res.size() == depth)
            res.push_back(n->val);
        
        rec(n->left, depth + 1, res);
        rec(n->right, depth + 1, res);
    }
    
public:
    int findBottomLeftValue(TreeNode *root) {
        vector<int> res;
        rec(root, 0, res);
        return res.back();
    }
};