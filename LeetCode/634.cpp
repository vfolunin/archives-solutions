class Solution {
public:
    int findDerangement(int n) {
        const long long MOD = 1e9 + 7;

        vector<long long> ways(n + 1);
        ways[0] = 1;

        for (int i = 1; i <= n; i++)
            ways[i] = (ways[i - 1] * i + (i % 2 ? -1 : 1)) % MOD;
        
        return ways[n];
    }
};