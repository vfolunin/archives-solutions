class Solution {
public:
    bool validDigit(int value, int digit) {
        string s = to_string(value);
        return count(s.begin(), s.end(), digit + '0') && s[0] != digit + '0';
    }
};