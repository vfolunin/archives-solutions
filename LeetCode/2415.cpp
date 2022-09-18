class Solution {
    void rec1(TreeNode *n, int depth, vector<vector<int>> &values) {
        if (!n)
            return;
        
        if (depth == values.size())
            values.emplace_back();
        values[depth].push_back(n->val);
        
        rec1(n->left, depth + 1, values);
        rec1(n->right, depth + 1, values);
    }
    
    void rec2(TreeNode *n, int depth, vector<vector<int>> &values) {
        if (!n)
            return;
        
        if (depth % 2) {
            n->val = values[depth].back();
            values[depth].pop_back();
        }
        
        rec2(n->left, depth + 1, values);
        rec2(n->right, depth + 1, values);
    }
    
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        vector<vector<int>> values;
        rec1(root, 0, values);
        rec2(root, 0, values);
        return root;
    }
};