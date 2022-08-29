class Solution {
    void rec(TreeNode *n, unordered_map<TreeNode *, multiset<int>> &paths, int &res) {
        if (!n)
            return;
        
        rec(n->left, paths, res);
        rec(n->right, paths, res);

        int l = (n->left && n->val == n->left->val ? *prev(paths[n->left].end()) + 1 : 0);
        int r = (n->right && n->val == n->right->val ? *prev(paths[n->right].end()) + 1 : 0);
   
        res = max({ res, l, r, l + r });
        
        paths[n].insert(l);
        paths[n].insert(r);
    }
    
public:
    int longestUnivaluePath(TreeNode *root) {
        unordered_map<TreeNode *, multiset<int>> paths;
        int res = 0;
        rec(root, paths, res);
        return res;
    }
};