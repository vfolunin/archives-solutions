class Solution {
public:
    int maxScore(string s) {
        int l0 = 0, r1 = count(s.begin(), s.end(), '1'), res = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            l0 += s[i] == '0';
            r1 -= s[i] == '1';
            res = max(res, l0 + r1);
        }
        return res;
    }
};