class Solution {
    vector<TreeNode *> firstPath;

    TreeNode *dfs(TreeNode *n, TreeNode *a, TreeNode *b, vector<TreeNode *> &path) {
        if (!n)
            return 0;
        
        path.push_back(n);
        
        if (n == a || n == b) {
            if (firstPath.empty()) {
                firstPath = path;
            } else {
                int i = 0;
                while (i + 1 < firstPath.size() && i + 1 < path.size() && firstPath[i + 1] == path[i + 1])
                    i++;
                return path[i];
            }
        }
        
        if (TreeNode *res = dfs(n->left, a, b, path); res)
            return res;
        if (TreeNode *res = dfs(n->right, a, b, path); res)
            return res;

        path.pop_back();
        
        return 0;
    }
    
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
        vector<TreeNode *> path;
        return dfs(root, a, b, path);
    }
};