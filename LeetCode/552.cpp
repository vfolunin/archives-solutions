class Solution {
public:
    int checkRecord(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> ways(2, vector<vector<long long>>(2, vector<long long>(3)));
        ways[0][0][0] = 1;
        
        for (int i = 0, cur = 0, next = 1; i < n; i++, cur ^= 1, next ^= 1) {
            ways[next][0][0] = (ways[cur][0][0] + ways[cur][0][1] + ways[cur][0][2]) % MOD;
            ways[next][0][1] = ways[cur][0][0];
            ways[next][0][2] = ways[cur][0][1];
            
            ways[next][1][0] = (ways[cur][0][0] + ways[cur][0][1] + ways[cur][0][2] +
                                     ways[cur][1][0] + ways[cur][1][1] + ways[cur][1][2]) % MOD;
            ways[next][1][1] = ways[cur][1][0];
            ways[next][1][2] = ways[cur][1][1];
        }
        
        long long res = 0;
        for (int a = 0; a <= 1; a++)
            for (int l = 0; l <= 2; l++)
                res += ways[n % 2][a][l];
        return res % MOD;
    }
};