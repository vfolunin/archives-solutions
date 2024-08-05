class Solution {
    vector<int> getPrimes(int n) {
        vector<int> isPrime(n + 1, 1), primes;

        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }

public:
    int nonSpecialCount(int l, int r) {
        int res = r - l + 1;
        for (int prime : getPrimes(1e5)) {
            long long value = 1LL * prime * prime;
            res -= l <= value && value <= r;
        }
        return res;
    }
};