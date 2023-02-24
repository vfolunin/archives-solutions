class Solution {
public:
    int longestPalindromeSubseq(string &s) {
        vector<vector<pair<int, char>>> res(s.size(), vector<pair<int, char>>(s.size()));

        for (int l = 0, r = 1; r < s.size(); l++, r++)
            if (s[l] == s[r])
                res[l][r] = { 2, s[l] };

        for (int len = 3; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                if (s[l] == s[r] && res[l + 1][r - 1].second != s[l])
                    res[l][r] = { res[l + 1][r - 1].first + 2, s[l] };
                else
                    res[l][r] = max(res[l + 1][r], res[l][r - 1]);
            }
        }

        return res[0][s.size() - 1].first;
    }
};