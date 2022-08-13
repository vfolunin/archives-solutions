class Solution {
    void rec(TreeNode *n, string &path, string &res) {
        path.push_back(n->val + 'a');
        
        if (!n->left && !n->right) {
            if (res.empty() || lexicographical_compare(path.rbegin(), path.rend(), res.rbegin(), res.rend()))
                res = path;
        } else {
            if (n->left)
                rec(n->left, path, res);
            if (n->right)
                rec(n->right, path, res);
        }
        
        path.pop_back();
    }
    
public:
    string smallestFromLeaf(TreeNode *root) {
        string path, res;
        rec(root, path, res);
        reverse(res.begin(), res.end());
        return res;
    }
};