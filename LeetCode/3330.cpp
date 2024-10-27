class Solution {
public:
    int possibleStringCount(string &s) {
        int row = 1, res = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                res += row - 1;
                row = 1;
            }
        }
        res += row - 1;
        return res;
    }
};