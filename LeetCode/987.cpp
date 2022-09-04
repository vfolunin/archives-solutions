class Solution {
    void rec(TreeNode *n, int y, int x, map<pair<int, int>, vector<int>> &cells) {
        if (!n)
            return;
        
        cells[{ x, y }].push_back(n->val);
        rec(n->left, y + 1, x - 1, cells);
        rec(n->right, y + 1, x + 1, cells);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<pair<int, int>, vector<int>> cells;
        rec(root, 0, 0, cells);
        
        vector<vector<int>> res;
        for (auto it = cells.begin(); it != cells.end(); it++) {
            if (it == cells.begin() || prev(it)->first.first != it->first.first)
                res.emplace_back();
            sort(it->second.begin(), it->second.end());
            res.back().insert(res.back().end(), it->second.begin(), it->second.end());
        }
        return res;
    }
};