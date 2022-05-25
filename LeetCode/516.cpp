class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> res(s.size(), vector<int>(s.size()));
        
        for (int i = 0; i < s.size(); i++)
            res[i][i] = 1;
        
        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                if (s[l] == s[r])
                    res[l][r] = 2 + res[l + 1][r - 1];
                else
                    res[l][r] = max(res[l + 1][r], res[l][r - 1]);
            }
        }
        
        return res[0][s.size() - 1];
    }
};