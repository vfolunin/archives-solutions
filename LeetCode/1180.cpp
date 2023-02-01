class Solution {
public:
    int countLetters(string &s) {
        int row = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                res += row * (row + 1) / 2;
                row = 1;
            }
        }
        res += row * (row + 1) / 2;
        return res;
    }
};