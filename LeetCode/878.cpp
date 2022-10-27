class Solution {
    long long count(long long n, long long a, long long b) {
        return n / a + n / b - n / lcm(a, b);
    }
    
public:
    int nthMagicalNumber(long long n, long long a, long long b) {
        long long l = 0, r = 1e18;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (count(m, a, b) < n)
                l = m;
            else
                r = m;
        }
        
        const long long MOD = 1e9 + 7;
        return r % MOD;
    }
};