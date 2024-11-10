class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

    int iterations(int oneCount) {
        static vector<int> memo(801, -1);
        int &res = memo[oneCount];
        if (res != -1)
            return res;
        
        if (oneCount == 1)
            return res = 1;
        
        return res = 1 + iterations(ones(oneCount));
    }

    long long rec(const string &s, int i, int oneCount, bool isPrefixOfS, int limit, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[i][oneCount][isPrefixOfS];
        if (res != -1)
            return res;

        if (i == s.size())
            return res = oneCount && iterations(oneCount) <= limit;

        const long long MOD = 1e9 + 7;
        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 1;

        for (int digit = 0; digit <= maxDigit; digit++) {
            int nextOneCount = oneCount + digit;
            int nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

            res = (res + rec(s, i + 1, nextOneCount, nextIsPrefixOfS, limit, memo)) % MOD;
        }

        return res;
    }

public:
    int countKReducibleNumbers(string &s, int limit) {
        vector memo(s.size() + 1, vector(s.size() + 1, vector<long long>(2, -1)));
        return rec(s, 0, 0, 1, limit, memo) - (iterations(count(s.begin(), s.end(), '1')) <= limit);
    }
};