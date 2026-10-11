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
    vector<int> maxPrimes(int valueLimit, int sumLimit) {
        int sum = 0;
        vector<int> res;
        for (int prime : getPrimes(valueLimit)) {
            if (sum + prime <= sumLimit) {
                sum += prime;
                res.push_back(prime);
            } else {
                break;
            }
        }
        return res;
    }
};