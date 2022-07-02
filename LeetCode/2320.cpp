class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> fib(n + 1);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < fib.size(); i++)
            fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
        
        return fib.back() * fib.back() % MOD;
    }
};