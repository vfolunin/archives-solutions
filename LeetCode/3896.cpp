class Solution {
    unordered_set<int> getPrimes(int n) {
        vector<int> isPrime(n + 1, 1);
        unordered_set<int> primes;

        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                primes.insert(i);
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }

public:
    int minOperations(vector<int> &a) {
        unordered_set<int> primes = getPrimes(2e5);
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            while (primes.contains(a[i]) == i % 2) {
                a[i]++;
                res++;
            }
        }

        return res;
    }
};