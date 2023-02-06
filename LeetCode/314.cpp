class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<int>> values;
        queue<pair<TreeNode *, int>> q;
        q.push({ root, 0 });

        while (!q.empty()) {
            auto [n, x] = q.front();
            q.pop();

            if (!n)
                continue;
            
            values[x].push_back(n->val);

            q.push({ n->left, x - 1 });
            q.push({ n->right, x + 1 });
        }

        vector<vector<int>> res;
        for (auto &[x, values] : values)
            res.push_back(values);
        return res;
    }
};