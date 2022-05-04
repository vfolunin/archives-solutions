class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        
        if (i == s.size())
            return 0;
        
        int sign = s[i] == '-' ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        
        long long value = 0;
        while (i < s.size() && isdigit(s[i])) {
            value = clamp(value * 10 + s[i] - '0', 0LL, (long long)1e10);
            i++;
        }
        
        return clamp(sign * value, (long long)INT_MIN, (long long)INT_MAX);
    }
};