class Solution {
public:
    int numberOfWays(int targetSum, int p) {
        vector<long long> ways(targetSum + 1);
        ways[0] = 1;
        
        for (int value = 1; 1; value++) {
            long long power = 1;
            for (int i = 0; i < p && power <= targetSum; i++)
                power *= value;
            
            if (power > targetSum)
                break;
            
            const long long MOD = 1e9 + 7;
            for (int sum = targetSum; sum >= power; sum--)
                ways[sum] = (ways[sum] + ways[sum - power]) % MOD;
        }
        
        return ways[targetSum];
    }
};