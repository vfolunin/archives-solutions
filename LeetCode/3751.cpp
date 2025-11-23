class Solution {
public:
    int totalWaviness(int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++) {
            string s = to_string(i);
            for (int j = 1; j + 1 < s.size(); j++)
                res += s[j - 1] < s[j] && s[j] > s[j + 1] || s[j - 1] > s[j] && s[j] < s[j + 1];
        }
        return res;
    }
};