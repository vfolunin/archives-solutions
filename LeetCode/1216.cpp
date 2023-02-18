class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> pSize(s.size(), vector<int>(s.size()));

        for (int i = 0; i < s.size(); i++)
            pSize[i][i] = 1;
        
        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                if (s[l] == s[r])
                    pSize[l][r] = pSize[l + 1][r - 1] + 2;
                else
                    pSize[l][r] = max(pSize[l + 1][r], pSize[l][r - 1]);
            }
        }

        return pSize[0][s.size() - 1] + k >= s.size();
    }
};