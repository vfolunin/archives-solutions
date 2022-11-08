class Solution {
public:
    string subStrHash(string &s, long long x, long long mod, int len, long long targetValue) {       
        long long curValue = 0, p = 1;
        for (int i = s.size() - len; i < s.size(); i++) {
            curValue = (curValue + p * (s[i] - 'a' + 1)) % mod;
            if (i + 1 < s.size())
                p = p * x % mod;
        }
        
        int from = s.size() - len;        
        for (int i = s.size() - len - 1; i >= 0; i--) {
            curValue = (curValue - p * (s[i + len] - 'a' + 1) % mod + mod) % mod;
            curValue = (curValue * x + (s[i] - 'a' + 1)) % mod;
            if (curValue == targetValue)
                from = i;
        }
        return s.substr(from, len);
    }
};