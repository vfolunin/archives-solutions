class Solution {
public:
    bool isPalindrome(long long x) {
        if (x < 0)
            return 0;
        
        long long rx = 0, n;
        for (n = x; n > 9; n /= 10)
            rx = rx * 10 + n % 10;
        rx = rx * 10 + n;
        
        return x == rx;
    }
};