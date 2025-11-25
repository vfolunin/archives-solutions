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
    vector<int> sumAndMultiply(string &s, vector<vector<int>> &queries) {
        string nonZeroS = s;
        nonZeroS.erase(remove(nonZeroS.begin(), nonZeroS.end(), '0'), nonZeroS.end());
        if (nonZeroS.empty())
            return vector<int>(queries.size());

        vector<int> nonZeroIndexL(s.size());
        for (int i = 0, nzi = -1; i < s.size(); i++) {
            if (s[i] != '0')
                nzi++;
            nonZeroIndexL[i] = nzi;
        }

        vector<int> nonZeroIndexR(s.size());
        for (int i = s.size() - 1, nzi = nonZeroS.size(); i >= 0; i--) {
            if (s[i] != '0')
                nzi--;
            nonZeroIndexR[i] = nzi;
        }

        vector<int> pDigitSum(nonZeroS.size());
        vector<long long> pValue(nonZeroS.size());
        const long long MOD = 1e9 + 7;

        for (int i = 0; i < nonZeroS.size(); i++) {
            pDigitSum[i] = (i ? pDigitSum[i - 1] : 0) + nonZeroS[i] - '0';
            pValue[i] = ((i ? pValue[i - 1] : 0) * 10 + nonZeroS[i] - '0') % MOD;
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = nonZeroIndexR[queries[i][0]];
            int r = nonZeroIndexL[queries[i][1]];
            if (l > r) 
                continue;

            int digitSum = pDigitSum[r] - (l ? pDigitSum[l - 1] : 0);
            long long value = (pValue[r] - (l ? pValue[l - 1] * binPow(10, r - l + 1, MOD) % MOD : 0) % MOD + MOD) % MOD;

            res[i] = digitSum * value % MOD;
        }
        return res;        
    }
};