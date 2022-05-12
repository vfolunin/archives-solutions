class Solution {
public:
    bool hasAlternatingBits(int n) {
        int remainder = n % 4;
        if (remainder == 0 || remainder == 3)
            return 0;
        
        while (n % 4 == remainder)
            n /= 4;
        return !n;
    }
};