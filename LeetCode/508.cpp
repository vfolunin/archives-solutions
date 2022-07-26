class Solution {
    int rec(TreeNode *n, unordered_map<int, int> &count) {
        if (!n)
            return 0;
        
        int sum = rec(n->left, count) + n->val + rec(n->right, count);
        count[sum]++;
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> count;
        rec(root, count);
        
        int maxCount = 0;
        for (auto &[sum, count] : count)
            maxCount = max(maxCount, count);
        
        vector<int> res;
        for (auto &[sum, count] : count)
            if (count == maxCount)
                res.push_back(sum);
        return res;
    }
};