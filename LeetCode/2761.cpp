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
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> primes = getPrimes(n);
        vector<vector<int>> pairs;

        for (int l = 0, r = (int)primes.size() - 1; l <= r; l++) {
            while (l <= r && primes[l] + primes[r] > n)
                r--;
                
            if (l <= r && primes[l] + primes[r] == n)
                pairs.push_back({ primes[l], primes[r] });
        }

        return pairs;
    }
};