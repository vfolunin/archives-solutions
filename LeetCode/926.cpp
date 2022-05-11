class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int l1 = 0, r0 = count(s.begin() + 1, s.end(), '0'), res = l1 + r0;
        for (int i = 1; i < s.size(); i++) {
            l1 += s[i - 1] == '1';
            r0 -= s[i] == '0';
            res = min(res, l1 + r0);
        }
        return res;
    }
};