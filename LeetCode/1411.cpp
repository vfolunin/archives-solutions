class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> res = { 0, 2, 9 };
        for (int i = 3; res.size() <= n; i++)
            res.push_back(((5 * res[i - 1] - 2 * res[i - 2]) % MOD + MOD) % MOD);
        
        return res[n] * 6 % MOD;
    }
};