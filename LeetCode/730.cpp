class Solution {
public:
    int countPalindromicSubsequences(string &s) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> ways(s.size(), vector<vector<long long>>(s.size(), vector<long long>(4)));
        for (int i = 0; i < s.size(); i++)
            for (int c = 0; c < 4; c++)
                ways[i][i][c] = s[i] == 'a' + c;
        
        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                for (int c = 0; c < 4; c++) {
                    if (s[l] != s[r]) {
                        ways[l][r][c] = (ways[l][r - 1][c] + ways[l + 1][r][c] - ways[l + 1][r - 1][c] + MOD) % MOD;
                    } else if (s[l] != 'a' + c) {
                        ways[l][r][c] = ways[l + 1][r - 1][c];
                    } else {
                        ways[l][r][c] = 2;
                        for (int pc = 0; pc < 4; pc++)
                            ways[l][r][c] += ways[l + 1][r - 1][pc];
                        ways[l][r][c] %= MOD;
                    }
                }
            }
        }
        
        long long res = 0;
        for (int c = 0; c < 4; c++)
            res = (res + ways[0][s.size() - 1][c]) % MOD;
        return res;
    }
};