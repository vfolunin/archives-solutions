class Solution {
    long long mul(long long a, long long b) {
        if (!b)
            return 0;
        if (b & 1)
            return mul(a, b - 1) + a;
        return mul(a + a, b / 2);
    }
    
public:
    int divide(long long a, long long b) {
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        
        bool neg = (a < 0) ^ (b < 0);
        a = abs(a);
        b = abs(b);
        
        long long l = 0, r = 1;
        while (mul(b, r) <= a)
            r <<= 2;
        
        while (l + 1 < r) {
            long long m = l + ((r - l) >> 1);
            if (mul(b, m) <= a)
                l = m;
            else
                r = m;
        }
        
        return neg ? -l : l;
    }
};