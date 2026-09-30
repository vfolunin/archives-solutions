class Solution {
    long long rec(const string &s, int i, bool hasLeadingZeros, bool isPrefixOfS, bool parity,
                  vector<vector<vector<vector<long long>>>> &memo) {
        long long &res = memo[i][hasLeadingZeros][isPrefixOfS][parity];
        if (res != -1)
            return res;

        if (i == s.size())
            return res = !parity;

        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;
        for (int digit = 0; digit <= maxDigit; digit++) {
            bool nextHasLeadingZeros = hasLeadingZeros && !digit;
            bool nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;
            bool nextParity = parity ^ (digit % 2 == 0 && (digit || !hasLeadingZeros));

            res += rec(s, i + 1, nextHasLeadingZeros, nextIsPrefixOfS, nextParity, memo);
        }

        return res;
    }

public:
    long long countEvenlyGoodIntegers(long long l, long long r) {
        vector memo(20, vector(2, vector(2, vector<long long>(2, -1))));
        long long rCount = rec(to_string(r), 0, 1, 1, 0, memo);

        memo.assign(20, vector(2, vector(2, vector<long long>(2, -1))));
        long long lCount = rec(to_string(l - 1), 0, 1, 1, 0, memo);

        return rCount - lCount;
    }
};