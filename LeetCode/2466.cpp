class Solution {
public:
    int countGoodStrings(int l, int r, int a, int b) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> ways(r + 1);
        ways[0] = 1;        
        for (int i = 0; i <= r; i++) {
            if (i >= a)
                ways[i] = (ways[i] + ways[i - a]) % MOD;
            if (i >= b)
                ways[i] = (ways[i] + ways[i - b]) % MOD;
        }
        
        long long res = 0;
        for (int i = l; i <= r; i++)
            res = (res + ways[i]) % MOD;
        return res;
    }
};