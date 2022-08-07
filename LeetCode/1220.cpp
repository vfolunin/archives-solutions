class Solution {
public:
    int countVowelPermutation(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> ways(5, 1);
        for (int i = 2; i <= n; i++) {
            ways = {
                (ways[1] + ways[2] + ways[4]) % MOD,
                (ways[0] + ways[2]) % MOD,
                (ways[1] + ways[3]) % MOD,
                ways[2] % MOD,
                (ways[2] + ways[3]) % MOD
            };
        }
        
        long long res = 0;
        for (long long ways : ways)
            res += ways;
        return res % MOD;
    }
};