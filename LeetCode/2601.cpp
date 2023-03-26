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
    bool primeSubOperation(vector<int> &a) {
        vector<int> primes = getPrimes(1000);

        for (int i = 0; i < a.size(); i++) {
            int limit = a[i] - (i ? a[i - 1] : 0);

            auto it = lower_bound(primes.begin(), primes.end(), limit);
            if (it != primes.begin())
                a[i] -= *prev(it);

            if (i && a[i - 1] >= a[i])
                return 0;
        }

        return 1;
    }
};