class Solution {
public:
    bool checkValidString(string &s) {
        vector<vector<int>> can(s.size(), vector<int>(s.size()));
        
        for (int i = 0; i < s.size(); i++)
            can[i][i] = s[i] == '*';
        
        for (int l = 0, r = 1; r < s.size(); l++, r++)
            can[l][r] = s[l] != ')' && s[r] != '(';
        
        for (int len = 3; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                can[l][r] = s[l] != ')' && s[r] != '(' && can[l + 1][r - 1];
                for (int m = l; !can[l][r] && m < r; m++)
                    can[l][r] |= can[l][m] && can[m + 1][r];
            }
        }
        
        return can[0][s.size() - 1];
    }
};