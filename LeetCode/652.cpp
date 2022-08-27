class Solution {
    int rec(TreeNode *n, map<vector<int>, int> &id, unordered_map<int, pair<int, TreeNode *>> &count) {
        if (!n)
            return -1e9;
        
        vector<int> descriptor = { rec(n->left, id, count), n->val, rec(n->right, id, count) };
        if (!id.count(descriptor))
            id[descriptor] = id.size();
        
        if (!count.count(id[descriptor]))
            count[id[descriptor]] = { 1, n };
        else
            count[id[descriptor]].first++;
        
        return id[descriptor];
    }
    
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        map<vector<int>, int> id;
        unordered_map<int, pair<int, TreeNode *>> count;
        rec(root, id, count);
        
        vector<TreeNode *> res;
        
        for (auto &[id, pair] : count)
            if (pair.first > 1)
                res.push_back(pair.second);
        
        return res;
    }
};