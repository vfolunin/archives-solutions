class Solution {
public:
    string convertToBase7(int n) {
        bool neg = 0;
        if (n < 0) {
            neg = 1;
            n = -n;
        }
        
        string res;
        while (n >= 7) {
            res += n % 7 + '0';
            n /= 7;
        }
        res += n + '0';
        
        if (neg)
            res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};