class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1)
            return 6;
        
        const long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> ways(n + 1, vector<vector<long long>>(7, vector<long long>(7)));
        
        for (int a = 1; a <= 6; a++)
            for (int b = 1; b <= 6; b++)
                if (a != b && gcd(a, b) == 1)
                    ways[2][a][b] = 1;
        
        for (int i = 3; i <= n; i++)
            for (int a = 1; a <= 6; a++)
                for (int b = 1; b <= 6; b++)
                    if (a != b && gcd(a, b) == 1)
                        for (int c = 1; c <= 6; c++)
                            if (a != c && b != c && gcd(b, c) == 1)
                                ways[i][a][b] = (ways[i][a][b] + ways[i - 1][b][c]) % MOD;
        
        long long res = 0;
        for (int a = 1; a <= 6; a++)
            for (int b = 1; b <= 6; b++)
                res = (res + ways[n][a][b]) % MOD;
        return res;
    }
};