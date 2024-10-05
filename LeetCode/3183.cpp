class Solution {
public:
    int numberOfWays(int targetSum) {
        const long long MOD = 1e9 + 7;
        vector<long long> ways(targetSum + 1);
        ways[0] = 1;
        
        for (int weight : { 1, 2, 6 })
            for (int sum = weight; sum < ways.size(); sum++)
                ways[sum] = (ways[sum] + ways[sum - weight]) % MOD;

        for (int sum = ways.size() - 1; sum; sum--)
            for (int weight : { 4, 8 })
                if (sum >= weight)
                    ways[sum] = (ways[sum] + ways[sum - weight]) % MOD;
        
        return ways.back();
    }
};