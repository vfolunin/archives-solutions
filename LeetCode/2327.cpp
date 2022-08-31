class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> count(n, vector<long long>(forget));
        count[0][0] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = delay; j < forget; j++)
                count[i][0] = (count[i][0] + count[i - 1][j - 1]) % MOD;
            
            for (int j = 1; j < forget; j++)
                count[i][j] = count[i - 1][j - 1];
        }
        
        long long res = accumulate(count.back().begin(), count.back().end(), 0LL);
        return res % MOD;
    }
};