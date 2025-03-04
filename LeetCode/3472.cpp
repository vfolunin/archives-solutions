class Solution {
public:
    int longestPalindromicSubsequence(string &s, int limit) {
        vector res(s.size(), vector(s.size(), vector<int>(limit + 1)));
        for (int i = 0; i < s.size(); i++)
            fill(res[i][i].begin(), res[i][i].end(), 1);
        
        for (int size = 2; size <= s.size(); size++) {
            for (int l = 0, r = size - 1; r < s.size(); l++, r++) {
                int delta = abs(s[l] - s[r]);
                delta = min(delta, 26 - delta);

                for (int curLimit = 0; curLimit < delta && curLimit <= limit; curLimit++)
                    res[l][r][curLimit] = max(res[l + 1][r][curLimit], res[l][r - 1][curLimit]);

                for (int curLimit = delta; curLimit <= limit; curLimit++)
                    res[l][r][curLimit] = max({ res[l + 1][r][curLimit], res[l][r - 1][curLimit], res[l + 1][r - 1][curLimit - delta] + 2 });
            }
        }

        return res[0][s.size() - 1][limit];
    }
};