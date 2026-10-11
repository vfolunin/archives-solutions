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
    vector<int> maxPrimeSubset(int valueLimit, int sumLimit) {
        vector<int> primes = getPrimes(valueLimit);
        reverse(primes.begin(), primes.end());

        vector<vector<int>> minCount(primes.size() + 1, vector<int>(sumLimit + 1, 1e9));
        vector<vector<int>> take(primes.size() + 1, vector<int>(sumLimit + 1));
        minCount[0][0] = 0;
        
        for (int size = 1; size <= primes.size(); size++) {
            int value = primes[size - 1];
            for (int sum = 0; sum <= sumLimit; sum++) {
                minCount[size][sum] = minCount[size - 1][sum];
                if (sum >= value && minCount[size][sum] >= minCount[size - 1][sum - value] + 1) {
                    minCount[size][sum] = minCount[size - 1][sum - value] + 1;
                    take[size][sum] = 1;
                }
            }
        }

        int sum = sumLimit;
        while (minCount.back()[sum] == 1e9)
            sum--;

        vector<int> res;
        for (int size = primes.size(); size; size--) {
            int value = primes[size - 1];
            if (take[size][sum]) {
                res.push_back(value);
                sum -= value;
            }
        }
        return res;
    }
};