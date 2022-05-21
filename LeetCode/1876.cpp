class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;
        for (int i = 0; i + 2 < s.size(); i++)
            res += s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2];
        return res;
    }
};