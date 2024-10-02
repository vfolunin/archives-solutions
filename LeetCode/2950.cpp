class Solution {
    int getCode(char c) {
        return (c - 'a' + 1) / 3 + 1;
    }

public:
    int countDivisibleSubstrings(string &s) {
        int res = 0;
        for (int l = 0; l < s.size(); l++) {
            int sum = 0;
            for (int r = l; r < s.size(); r++) {
                sum += getCode(s[r]);
                res += sum % (r - l + 1) == 0;
            }
        }
        return res;
    }
};