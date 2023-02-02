class Solution {
public:
    string toHexspeak(string &s) {
        string digits = "OI--------ABCDEF", res;
        for (long long value = stoll(s); value; value /= 16) {
            if (digits[value % 16] == '-')
                return "ERROR";
            res += digits[value % 16];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};