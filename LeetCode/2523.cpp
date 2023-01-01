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
    vector<int> closestPrimes(int l, int r) {
        vector<int> primes = getPrimes(r);

        int bestDist = 1e9, bestA = -1, bestB = -1;
        for (int i = 0; i + 1 < primes.size(); i++) {
            if (l <= primes[i] && bestDist > primes[i + 1] - primes[i]) {
                bestDist = primes[i + 1] - primes[i];
                bestA = primes[i];
                bestB = primes[i + 1];
            }
        }

        return { bestA, bestB };
    }
};