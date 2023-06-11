class Solution {
    bool isGood(string &s, int l, int r) {
        int repetitionCount = 0;
        for (int i = l; i < r; i++)
            repetitionCount += s[i] == s[i + 1];
        return repetitionCount <= 1;
    }
    
public:
    int longestSemiRepetitiveSubstring(string &s) {
        for (int len = s.size(); len; len--)
            for (int l = 0, r = len - 1; r < s.size(); l++, r++)
                if (isGood(s, l, r))
                    return len;
        return 1;
    }
};