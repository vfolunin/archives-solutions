class Solution {
public:
    int maxPower(string s) {
        int cur = 1, res = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                cur++;
            else
                cur = 1;
            res = max(res, cur);
        }
        return res;
    }
};