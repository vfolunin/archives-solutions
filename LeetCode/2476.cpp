class Solution {
    void traverse(TreeNode *n, vector<int> &a) {
        if (!n)
            return;
        traverse(n->left, a);
        a.push_back(n->val);
        traverse(n->right, a);
    }
    
public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        vector<int> a;
        traverse(root, a);
        
        vector<vector<int>> res(queries.size(), vector<int>(2, -1));
        for (int i = 0; i < queries.size(); i++) {
            auto it = lower_bound(a.begin(), a.end(), queries[i]);
            
            if (it != a.end() && *it == queries[i])
                res[i][0] = *it;
            else if (it != a.begin())
                res[i][0] = *prev(it);
            
            if (it != a.end())
                res[i][1] = *it;
        }
        return res;
    }
};