class Solution {
public:
    int strangePrinter(string &s) {
        s.erase(unique(s.begin(), s.end()), s.end());
        
        vector<vector<int>> res(s.size(), vector<int>(s.size()));
        
        for (int i = 0; i < s.size(); i++)
            res[i][i] = 1;
        
        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                res[l][r] = 1e9;
                for (int m = l; m < r; m++)
                    res[l][r] = min(res[l][r], res[l][m] + res[m + 1][r]);
                res[l][r] -= s[l] == s[r];
            }
        }
        
        return res[0][s.size() - 1];
    }
};