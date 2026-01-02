class Solution {
public:
    string lexicographicallySmallestString(string &s) {
        vector<vector<string>> res(s.size() + 1, vector<string>(s.size() + 1));

        for (int len = 1; len <= s.size(); len++) {
            for (int l = 0, r = l + len - 1; r < s.size(); l++, r++) {
                res[l][r] = s[l] + res[l + 1][r];

                for (int m = l + 1; m <= r; m++)
                    if ((abs(s[l] - s[m]) == 1 || abs(s[l] - s[m]) == 25) && res[l + 1][m - 1] == "")
                        res[l][r] = min(res[l][r], res[m + 1][r]);
            }
        }

        return res[0][s.size() - 1];
    }
};