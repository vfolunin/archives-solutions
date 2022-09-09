class Solution {
public:
    int minInsertions(string &s) {
        vector<vector<int>> res(s.size(), vector<int>(s.size()));
        
        for (int i = 0; i < s.size(); i++)
            res[i][i] = 1;
        
        for (int len = 2; len <= s.size(); len++)
            for (int l = 0, r = len - 1; r < s.size(); l++, r++)
                res[l][r] = s[l] == s[r] ? res[l + 1][r - 1] + 2 : max(res[l][r - 1], res[l + 1][r]);
        
        return s.size() - res[0][s.size() - 1];
    }
};