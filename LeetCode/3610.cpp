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
    int minNumberOfPrimes(int targetSum, int limit) {
        vector<int> primes = getPrimes(1e4);
        primes.resize(limit);

        vector<int> minCost(targetSum + 1, 1e9);
        minCost[0] = 0;
        for (int prime : primes)
            for (int sum = prime; sum <= targetSum; sum++)
                minCost[sum] = min(minCost[sum], minCost[sum - prime] + 1);
        
        return minCost.back() != 1e9 ? minCost.back() : -1;
    }
};