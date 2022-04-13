class Solution {
public:
    int mySqrt(long long x) {
        long long l = 0, r = x + 1;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (m * m <= x)
                l = m;
            else
                r = m;
        }
        return l;
    }
};