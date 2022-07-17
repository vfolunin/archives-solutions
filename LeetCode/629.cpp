class Solution {
public:
    int kInversePairs(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> ways(n + 1, vector<long long>(k + 1));
        ways[1][0] = 1;
        
        for (int size = 2; size <= n; size++) {
            for (int inv = 1; inv < ways[size - 1].size(); inv++)
                ways[size - 1][inv] = (ways[size - 1][inv] + ways[size - 1][inv - 1]) % MOD;
            
            for (int inv = 0; inv <= k; inv++) {
                int from = max(0, inv - size + 1);
                ways[size][inv] = ((ways[size - 1][inv] - (from ? ways[size - 1][from - 1] : 0)) % MOD + MOD) % MOD;
            }
        }
        
        return ways[n][k];
    }
};