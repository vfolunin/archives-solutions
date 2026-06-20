class Solution {
    long long rec(string &s, int i, int last, int limit, bool isPrefixOfS, bool hasLeadingZeros,
                  vector<vector<vector<vector<long long>>>> &memo) {
        long long &res = memo[i][last][isPrefixOfS][hasLeadingZeros];
        if (res != -1)
            return res;

        if (i == s.size())
            return 1;

        res = 0;
        int minDigit = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;
        if (!hasLeadingZeros) {
            minDigit = max(minDigit, last - limit);
            maxDigit = min(maxDigit, last + limit);
        }

        for (int digit = minDigit; digit <= maxDigit; digit++) {
            bool nextIsPrefixOfS = isPrefixOfS && digit == s[i] - '0';
            bool nextHasLeadingZeros = hasLeadingZeros && !digit;

            res += rec(s, i + 1, digit, limit, nextIsPrefixOfS, nextHasLeadingZeros, memo);
        }

        return res;
    }

public:
    long long goodIntegers(long long l, long long r, int limit) {
        string ls = to_string(l - 1);
        vector memo(ls.size() + 1, vector(10, vector(2, vector<long long>(2, -1))));
        long long lCount = rec(ls, 0, 0, limit, 1, 1, memo);

        string rs = to_string(r);
        memo.assign(rs.size() + 1, vector(10, vector(2, vector<long long>(2, -1))));
        long long rCount = rec(rs, 0, 0, limit, 1, 1, memo);

        return rCount - lCount;
    }
};