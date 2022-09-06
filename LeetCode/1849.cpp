class Solution {
    bool can(string &s, int from, long long value) {
        if (from == s.size())
            return 1;
        
        long long sValue = 0;
        
        if (!from) {
            for ( ; from + 1 < s.size() && sValue < 1e10; from++) {
                sValue = sValue * 10 + s[from] - '0';
                if (can(s, from + 1, sValue - 1))
                    return 1;
            }
        } else {
            for ( ; from < s.size() && sValue <= value; from++) {
                sValue = sValue * 10 + s[from] - '0';
                if (sValue == value && can(s, from + 1, value - 1))
                    return 1;
            }
        }
        
        return 0;
    }
    
public:
    bool splitString(string &s) {
        return can(s, 0, 0);
    }
};