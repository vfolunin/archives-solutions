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
    int largestPrime(int n) {
        vector<int> primes = getPrimes(n);

        int sum = 0, res = 0;
        for (int prime : primes) {
            if (sum + prime > n)
                break;
                
            sum += prime;
            if (binary_search(primes.begin(), primes.end(), sum))
                res = sum;
        }
        return res;
    }
};