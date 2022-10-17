class Solution {
    int rec(string &s, int i) {
        if (i == s.size()) {
            int h = (s[0] - '0') * 10 + (s[1] - '0');
            int m = (s[3] - '0') * 10 + (s[4] - '0');
            return 0 <= h && h < 24 && 0 <= m && m < 60;
        }
        
        int res = 0;
        
        if (s[i] == '?') {
            for (s[i] = '0'; s[i] <= '9'; s[i]++)
                res += rec(s, i + 1);
            s[i] = '?';
        } else {
            res += rec(s, i + 1);
        }
        
        return res;
    }
    
public:
    int countTime(string &s) {
        return rec(s, 0);
    }
};