class Solution {
public:
    int minOperations(string &s) {
        int res = 1e9;
        for (int i = 0; i < s.size(); i++) {
            int cur = i;
            for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
                int diff = abs(s[(i + l) % s.size()] - s[(i + r) % s.size()]);
                diff = min(diff, 26 - diff);
                cur += diff;
            }
            res = min(res, cur);
        }
        return res;
    }
};