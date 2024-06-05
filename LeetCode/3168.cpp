class Solution {
public:
    int minimumChairs(string &s) {
        int cur = 0, res = 0;
        for (char c : s) {
            cur += c == 'E' ? 1 : -1;
            res = max(res, cur);
        }
        return res;
    }
};