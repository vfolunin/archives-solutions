class Solution {
    void traverse(TreeNode *n, vector<int> &values) {
        if (!n)
            return;
        
        traverse(n->left, values);
        values.push_back(n->val);
        traverse(n->right, values);
    }

public:
    vector<int> closestKValues(TreeNode *root, double target, int count) {
        vector<int> values;
        traverse(root, values);

        int r = lower_bound(values.begin(), values.end(), target) - values.begin();
        int l = r - 1;
        vector<int> res;

        while (res.size() < count) {
            if (r == values.size() || 0 <= l && target - values[l] <= values[r] - target)
                res.push_back(values[l--]);
            else
                res.push_back(values[r++]);
        }

        return res;
    }
};