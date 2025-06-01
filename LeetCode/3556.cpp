class Solution {
    bool isPrime(long long n) {
        if (n < 2)
            return 0;
        
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        
        return 1;
    }

public:
    long long sumOfLargestPrimes(string &s) {
        set<long long> primes;
        for (int l = 0; l < s.size(); l++) {
            for (int r = l; r < s.size(); r++) {
                long long value = stoll(s.substr(l, r - l + 1));
                if (isPrime(value))
                    primes.insert(value);
            }
        }
        
        long long res = 0;
        for (int i = 0; i < 3 && !primes.empty(); i++) {
            res += *prev(primes.end());
            primes.erase(prev(primes.end()));
        }
        return res;
    }
};