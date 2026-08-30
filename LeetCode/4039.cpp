class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int sumDecoded(vector<long long> &a) {
        const long long MOD = 1e9 + 7;
        long long sum = 0;

        for (long long value : a) {
            int width = value % 10;

            string s = to_string(value);
            s.pop_back();
            
            sum = (sum + binPow(stoll(s.substr(0, width)), stoll(s.substr(width)), MOD)) % MOD;
        }

        return sum;
    }
};