class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> ways(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1)));
        vector<vector<vector<long long>>> waysSum = ways;
        
        for (int maxValue = 1; maxValue <= m; maxValue++) {
            ways[1][maxValue][1] = 1;
            waysSum[1][maxValue][1] = (waysSum[1][maxValue - 1][1] + ways[1][maxValue][1]) % MOD;
        }
        
        for (int size = 2; size <= n; size++) {
            for (int maxValue = 1; maxValue <= m; maxValue++) {
                for (int cost = 1; cost <= k; cost++) {
                    ways[size][maxValue][cost] = ways[size - 1][maxValue][cost] * maxValue % MOD;
                    ways[size][maxValue][cost] = (ways[size][maxValue][cost] + waysSum[size - 1][maxValue - 1][cost - 1]) % MOD;
                    waysSum[size][maxValue][cost] = (waysSum[size][maxValue - 1][cost] + ways[size][maxValue][cost]) % MOD;
                }
            }
        }
        
        return waysSum[n][m][k];
    }
};