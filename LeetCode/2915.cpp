class Solution {
public:
    int lengthOfLongestSubsequence(vector<int> &a, int targetSum) {
        vector<int> res(targetSum + 1, -1);
        res[0] = 0;
        
        for (int value : a)
            for (int sum = targetSum; sum >= value; sum--)
                if (res[sum - value] != -1)
                    res[sum] = max(res[sum], res[sum - value] + 1);
        
        return res[targetSum];
    }
};