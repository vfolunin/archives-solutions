class Solution {
public:
    int longestPalindrome(string &a, string &b) {
        string s = a + b;
        
        vector<vector<int>> pSize(s.size(), vector<int>(s.size()));
        int res = 0;
        
        for (int i = 0; i < s.size(); i++)
            pSize[i][i] = 1;
        
        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                if (s[l] == s[r]) {
                    pSize[l][r] = pSize[l + 1][r - 1] + 2;
                    if (l < a.size() && r >= a.size())
                        res = max(res, pSize[l][r]);
                } else {
                    pSize[l][r] = max(pSize[l + 1][r], pSize[l][r - 1]);
                }
            }
        }
        
        return res;
    }
};