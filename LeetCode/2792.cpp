class Solution {
    multiset<int> rec(TreeNode *n, int k, int &res) {
        if (!n)
            return {};

        multiset<int> values = rec(n->left, k, res);
        multiset<int> rValues = rec(n->right, k, res);

        values.insert(rValues.begin(), rValues.end());
        while (values.size() > k)
            values.erase(prev(values.end()));
        
        res += values.size() == k && *prev(values.end()) < n->val;

        values.insert(n->val);
        return values;
    }

public:
    int countGreatEnoughNodes(TreeNode *root, int k) {
        int res = 0;
        rec(root, k, res);
        return res;
    }
};