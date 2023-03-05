class Solution {
    void rec(TreeNode *n, int depth, vector<long long> &sums) {
        if (!n)
            return;
        
        if (sums.size() == depth)
            sums.resize(depth + 1);
        sums[depth] += n->val;
        
        rec(n->left, depth + 1, sums);
        rec(n->right, depth + 1, sums);
    }
    
public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        vector<long long> sums;
        rec(root, 0, sums);

        sort(sums.rbegin(), sums.rend());

        if (k - 1 < sums.size())
            return sums[k - 1];
        else
            return -1;
    }
};