class Solution {
    bool can(long long n, long long a, long long b, long long c, long long x) {
        long long count = x / a + x / b + x / c;
        count -= x / lcm(a, b) + x / lcm(a, c) + x / lcm(b, c);
        count += x / lcm(a, lcm(b, c));
        return count >= n;
    }
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 0, r = 1;
        while (!can(n, a, b, c, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(n, a, b, c, m))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};