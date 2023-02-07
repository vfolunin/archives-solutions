class Solution {
    void rec(TreeNode *n, int target, vector<int> &path, vector<int> &targetPath) {
        if (!n)
            return;
            
        path.push_back(n->val);
        
        if (n->val == target)
            targetPath = path;
        
        rec(n->left, target, path, targetPath);
        rec(n->right, target, path, targetPath);
        
        path.pop_back();
    }

public:
    int findDistance(TreeNode *root, int a, int b) {
        vector<int> path, pathA, pathB;
        rec(root, a, path, pathA);
        rec(root, b, path, pathB);

        int commonPrefix = 0;
        while (commonPrefix < pathA.size() && commonPrefix < pathB.size() && pathA[commonPrefix] == pathB[commonPrefix])
            commonPrefix++;
        return pathA.size() + pathB.size() - 2 * commonPrefix;
    }
};