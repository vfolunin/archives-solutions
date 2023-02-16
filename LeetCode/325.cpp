class Solution {
public:
    int maxSubArrayLen(vector<int> &a, int targetSum) {
        unordered_map<long long, int> seen = { { 0, -1 } };
        long long sum = 0;
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            if (seen.count(sum - targetSum))
                res = max(res, i - seen[sum - targetSum]);
            if (!seen.count(sum))
                seen[sum] = i;
        }

        return res;        
    }
};