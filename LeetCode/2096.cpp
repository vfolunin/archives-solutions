class Solution {
    void rec(TreeNode *n, string &path, int a, int b, string &aPath, string &bPath) {
        if (!n)
            return;
        
        if (n->val == a)
            aPath = path;
        if (n->val == b)
            bPath = path;
        
        path.push_back('L');
        rec(n->left, path, a, b, aPath, bPath);
        path.back() = 'R';
        rec(n->right, path, a, b, aPath, bPath);
        path.pop_back();
    }
    
public:
    string getDirections(TreeNode *root, int a, int b) {
        string path, pathA, pathB;
        rec(root, path, a, b, pathA, pathB);
        
        int commonPrefix = 0;
        while (commonPrefix < pathA.size() && commonPrefix < pathB.size() && pathA[commonPrefix] == pathB[commonPrefix])
            commonPrefix++;
        
        return string(pathA.size() - commonPrefix, 'U') + pathB.substr(commonPrefix);
    }
};