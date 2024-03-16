class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int sumOfPower(vector<int> &a, int targetSum) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> subsequenceCount(a.size() + 1, vector<long long>(targetSum + 1));
        subsequenceCount[0][0] = 1;

        for (int value : a)
            for (int size = a.size(); size; size--)
                for (int sum = value; sum <= targetSum; sum++)
                    subsequenceCount[size][sum] = (subsequenceCount[size][sum] + subsequenceCount[size - 1][sum - value]) % MOD;
        
        long long res = 0;
        for (int size = 1; size <= a.size(); size++)
            res = (res + subsequenceCount[size][targetSum] * binPow(2, a.size() - size, MOD) % MOD) % MOD;        
        return res;
    }
};