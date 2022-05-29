class Solution {
public:
    int combinationSum4(vector<int> &a, int target) {
        vector<long long> ways(target + 1);
        ways[0] = 1;
        
        for (int sum = 1; sum <= target; sum++)
            for (int value : a)
                if (sum >= value)
                    ways[sum] = min(1LL << 60, ways[sum] + ways[sum - value]);
        
        return ways[target];
    }
};