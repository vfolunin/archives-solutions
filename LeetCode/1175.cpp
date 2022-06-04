const long long MOD = 1e9 + 7;

class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return 0;
        for (int d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        return 1;
    }
    
public:
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        vector<long long> factorial(n + 1);
        factorial[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            primeCount += isPrime(i);
            factorial[i] = factorial[i - 1] * i % MOD;
        }
        
        return factorial[primeCount] * factorial[n - primeCount] % MOD;
    }
};