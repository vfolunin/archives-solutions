class Solution {
    int getHeight(TreeNode *n) {
        return n ? 1 + max(getHeight(n->left), getHeight(n->right)) : 0;
    }
    
    void fill(TreeNode *n, int depth, int l, int r, vector<vector<string>> &res) {
        if (!n)
            return;
        
        int m = l + (r - l) / 2;
        res[depth][m] = to_string(n->val);
        fill(n->left, depth + 1, l, m - 1, res);
        fill(n->right, depth + 1, m + 1, r, res);
    }
    
public:
    vector<vector<string>> printTree(TreeNode *root) {
        int h = getHeight(root);
        vector<vector<string>> res(h, vector<string>((1 << h) - 1));
        fill(root, 0, 0, res[0].size() - 1, res);
        return res;
    }
};