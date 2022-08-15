class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> ways(n + 1, vector<long long>(3));
        ways[0][0] = ways[1][0] = ways[1][1] = ways[1][2] = 1;
        
        for (int i = 2; i <= n; i++) {
            ways[i][0] = (ways[i - 1][0] + ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2]) % MOD;
            ways[i][1] = (ways[i - 1][0] + ways[i - 1][2]) % MOD;
            ways[i][2] = (ways[i - 1][0] + ways[i - 1][1]) % MOD;
        }
        
        return ways[n][0];
    }
};