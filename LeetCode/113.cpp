class Solution {
    void rec(TreeNode *n, int sum, int target, vector<int> &path, vector<vector<int>> &paths) {
        if (!n)
            return;
        
        sum += n->val;        
        path.push_back(n->val);
        
        if (!n->left && !n->right) {
            if (sum == target)
                paths.push_back(path);
        } else {
            rec(n->left, sum, target, path, paths);
            rec(n->right, sum, target, path, paths);
        }
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        vector<int> path;
        vector<vector<int>> paths;
        rec(root, 0, target, path, paths);
        return paths;
    }
};