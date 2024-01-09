class Solution {
    long long rec(const string &s, int i, bool isPrefixOfS, int digitLimit, string &suffix, vector<vector<long long>> &memo) {
        long long &res = memo[i][isPrefixOfS];
        if (res != -1)
            return res;

        if (i == s.size())
            return res = 1;

        if (s.size() < suffix.size())
            return res = 0;

        res = 0;

        int minDigit = 0;
        int maxDigit = min(isPrefixOfS ? s[i] - '0' : 9, digitLimit);
        if (i + suffix.size() >= s.size()) {
            minDigit = max(minDigit, suffix[suffix.size() + i - s.size()] - '0');
            maxDigit = min(maxDigit, suffix[suffix.size() + i - s.size()] - '0');
        }

        for (int digit = minDigit; digit <= maxDigit; digit++) {
            int nextIsPrefixOfS = isPrefixOfS && digit == s[i] - '0';
            res += rec(s, i + 1, nextIsPrefixOfS, digitLimit, suffix, memo);
        }

        return res;
    }

public:
    long long numberOfPowerfulInt(long long l, long long r, int digitLimit, string &suffix) {
        vector<vector<long long>> memo(20, vector<long long>(2, -1));
        long long rCount = rec(to_string(r), 0, 1, digitLimit, suffix, memo);

        memo.assign(20, vector<long long>(2, -1));
        long long lCount = rec(to_string(l - 1), 0, 1, digitLimit, suffix, memo);

        return rCount - lCount;
    }
};