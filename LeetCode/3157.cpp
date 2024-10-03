class Solution {
    void rec(TreeNode *n, int depth, vector<long long> &sum) {
        if (!n)
            return;

        if (sum.size() == depth)
            sum.emplace_back();
        sum[depth] += n->val;

        rec(n->left, depth + 1, sum);
        rec(n->right, depth + 1, sum);
    }

public:
    int minimumLevel(TreeNode *root) {
        vector<long long> sum;
        rec(root, 0, sum);
        return min_element(sum.begin(), sum.end()) - sum.begin() + 1;
    }
};