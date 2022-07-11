class Solution {
    void traverse(TreeNode *n, int depth, vector<deque<int>> &res) {
        if (!n)
            return;
        
        if (res.size() == depth)
            res.emplace_back();
        
        if (depth % 2)
            res[depth].push_front(n->val);
        else
            res[depth].push_back(n->val);
        
        traverse(n->left, depth + 1, res);
        traverse(n->right, depth + 1, res);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<deque<int>> deques;
        traverse(root, 0, deques);
        
        vector<vector<int>> res;
        for (deque<int> &d : deques)
            res.push_back({ d.begin(), d.end() });
        return res;
    }
};