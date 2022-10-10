class Solution {
    long long factorialZeroCount(long long n) {
        long long res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
    
    long long lessThan(long long z) {
        if (!z)
            return 0;
        
        long long l = 0, r = 1;
        while (factorialZeroCount(r) < z)
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (factorialZeroCount(m) < z)
                l = m;
            else
                r = m;
        }
        
        return r;
    }
    
public:
    int preimageSizeFZF(int k) {
        return lessThan(k + 1) - lessThan(k);
    }
};