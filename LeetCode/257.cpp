class Solution {
    void rec(TreeNode *n, vector<int> &path, vector<string> &paths) {
        if (!n->left && !n->right) {
            paths.emplace_back();
            for (int value : path)
                paths.back() += to_string(value) + "->";
            paths.back() += to_string(n->val);
            return;
        }
        
        path.push_back(n->val);
        if (n->left)
            rec(n->left, path, paths);
        if (n->right)
            rec(n->right, path, paths);
        path.pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> path;
        vector<string> paths;
        rec(root, path, paths);
        return paths;
    }
};