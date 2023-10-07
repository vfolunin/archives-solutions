class Solution {
public:
    string smallestNumber(long long n) {
        if (n == 1)
            return "1";
        
        string res;
        for (int digit = 9; digit > 1; digit--) {
            while (n % digit == 0) {
                res += digit + '0';
                n /= digit;
            }
        }

        if (n > 1)
            return "-1";
        
        reverse(res.begin(), res.end());
        return res;
    }
};