class Solution {
public:
    int longestContinuousSubstring(string &s) {
        int res = 1, cur = 1;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] + 1 == s[i])
                cur++;
            else
                cur = 1;
            res = max(res, cur);
        }
        
        return res;
    }
};