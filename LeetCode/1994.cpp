class Solution {
    static const long long MOD = 1e9 + 7;
    
    vector<int> getPrimes() {
        const int N = 30;
        vector<int> isPrime(N, 1), primes;

        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < N; j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }
    
    long long rec(unordered_map<int, int> &maskCount, unordered_map<int, int>::iterator it, int mask) {
        if (it == maskCount.end())
            return mask > 0;
        
        long long res = rec(maskCount, next(it), mask);
        if ((mask & it->first) == 0)
            res = (res + rec(maskCount, next(it), mask | it->first) * it->second % MOD) % MOD;
        return res;
    }
    
public:
    int numberOfGoodSubsets(vector<int> &a) {
        vector<int> primes = getPrimes();
        
        unordered_map<int, int> maskCount;
        for (int value : a) {
            int mask = 0, ok = 1;
            for (int bit = 0; bit < primes.size(); bit++) {
                if (value % (primes[bit] * primes[bit]) == 0) {
                    ok = 0;
                    break;
                } else if (value % primes[bit] == 0) {
                    mask |= 1 << bit;
                }
            }
            if (ok)
                maskCount[mask]++;
        }
        
        long long pow = 1;
        for (int i = 0; i < maskCount[0]; i++)
            pow = pow * 2 % MOD;
        maskCount.erase(0);
        
        return pow * rec(maskCount, maskCount.begin(), 0) % MOD;
    }
};