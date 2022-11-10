class Solution {
    const long long MOD = 1e9 + 7;

    vector<long long> precalcFactorials() {
        vector<long long> memo(3e3 + 1);
        memo[0] = 1;
        for (int i = 1; i < memo.size(); i++)
            memo[i] = memo[i - 1] * i % MOD;
        return memo;
    }

    long long factorial(int n) {
        static vector<long long> memo = precalcFactorials();
        return memo[n];
    }
    
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2, MOD);
    }
    
    long long anagramCount(vector<int> letterCount) {
        long long num = 0, den = 1;
        for (int count : letterCount) {
            num = (num + count) % MOD;
            den = den * factorial(count) % MOD;
        }
        return factorial(num) * inv(den) % MOD;
    }
    
public:
    int makeStringSorted(string &s) {
        vector<int> letterCount(26);
        for (char c : s)
            letterCount[c - 'a']++;

        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (char c = 0; c < s[i] - 'a'; c++) {
                if (!letterCount[c])
                    continue;
                letterCount[c]--;
                res = (res + anagramCount(letterCount)) % MOD;
                letterCount[c]++;
            }
            letterCount[s[i] - 'a']--;
        }

        return res;
    }
};