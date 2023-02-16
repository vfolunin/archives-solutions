class Solution {
    int rec(TreeNode *n, unordered_map<TreeNode *, int> &sum) {
        return sum[n] = n ? rec(n->left, sum) + n->val + rec(n->right, sum) : 0;
    }

public:
    bool checkEqualTree(TreeNode *root) {
        unordered_map<TreeNode *, int> sum;
        int totalSum = rec(root, sum);

        if (totalSum % 2)
            return 0;
        
        for (auto &[n, sum] : sum)
            if (n && n != root && sum == totalSum / 2)
                return 1;

        return 0;
    }
};