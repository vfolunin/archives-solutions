class Solution {    
public:
    int waysToReachTarget(int target, vector<vector<int>> &types) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> ways(types.size() + 1, vector<long long>(target + 1));
        ways[0][0] = 1;
        
        for (int i = 1; i <= types.size(); i++)
            for (int count = 0; count <= types[i - 1][0]; count++)
                for (int sum = count * types[i - 1][1]; sum <= target; sum++)
                     ways[i][sum] = (ways[i][sum] + ways[i - 1][sum - count * types[i - 1][1]]) % MOD;
        
        return ways[types.size()][target];
    }
};