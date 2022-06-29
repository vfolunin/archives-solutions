class Solution {
    long long phi(long long n) {
        long long res = n;
        for (long long d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                while (n % d == 0)
                    n /= d;
                res -= res / d;
            }
        }
        if (n > 1)
            res -= res / n;
        return res;
    }
    
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }
    
public:
    int superPow(int a, vector<int> &b) {
        long long mod = 1337, phiMod = phi(mod);
        
        long long p = 0;
        for (int digit : b)
            p = (p * 10 + digit) % phiMod;
        
        return binPow(a, p, mod);        
    }
};