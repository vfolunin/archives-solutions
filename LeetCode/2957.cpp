class Solution {
public:
    int removeAlmostEqualCharacters(string &s) {
        int row = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i - 1] - s[i]) <= 1) {
                row++;
            } else {
                res += row / 2;
                row = 1;
            }
        }
        res += row / 2;
        return res;
    }
};