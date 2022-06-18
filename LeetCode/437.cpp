class Solution {
    int rec(TreeNode *n, int targetSum, long long prefixSum, unordered_map<long long, int> &prefixSums) {
        if (!n)
            return 0;
        
        prefixSum += n->val;
        prefixSums[prefixSum]++;
        
        int res = 0;
        
        if (prefixSums.count(prefixSum - targetSum))
            res += prefixSums[prefixSum - targetSum];
        
        res += rec(n->left, targetSum, prefixSum, prefixSums);
        res += rec(n->right, targetSum, prefixSum, prefixSums);
        
        prefixSums[prefixSum]--;
        
        return res - !targetSum;
    }
    
public:
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<long long, int> prefixSums = { { 0, 1 } };
        return rec(root, targetSum, 0, prefixSums);
    }
};