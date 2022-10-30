class Solution {    
    void rec(TreeNode *n, int p, unordered_map<int, int> &height, unordered_map<int, int> &depth) {
        if (!n)
            return;
        
        depth[n->val] = p ? depth[p] + 1 : 0;
        
        rec(n->left, n->val, height, depth);
        rec(n->right, n->val, height, depth);
        
        height[n->val] = 1 + max(n->left ? height[n->left->val] : -1, n->right ? height[n->right->val] : -1);
    }
    
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        unordered_map<int, int> height, depth;
        rec(root, 0, height, depth);
        
        unordered_map<int, vector<int>> level;
        for (auto &[v, d] : depth)
            level[d].push_back(v);
        
        for (auto &[d, level] : level) {
            sort(level.begin(), level.end(), [&](int a, int b) {
                return height[a] > height[b];
            });
        }
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            int v = queries[i], d = depth[v];
            vector<int> &l = level[d];
            res[i] = d + (l.size() == 1 ? -1 : height[v == l[0] ? l[1] : l[0]]);
        }
        return res;
    }
};