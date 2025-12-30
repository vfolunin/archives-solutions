class Solution {
    long long rec(const string &s, int i, int balance, bool isPrefixOfS, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[i][balance + 100][isPrefixOfS];
        if (res != -1)
            return res;

        if (i == s.size())
            return res = !balance;

        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;

        for (int digit = 0; digit <= maxDigit; digit++) {
            int nextBalance = balance + (i % 2 ? digit : -digit);
            bool nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

            res += rec(s, i + 1, nextBalance, nextIsPrefixOfS, memo);
        }

        return res;
    }

public:
    long long countBalanced(long long l, long long r) {
        vector memo(20, vector(200, vector<long long>(2, -1)));
        long long rCount = rec(to_string(r), 0, 0, 1, memo);

        memo.assign(20, vector(200, vector<long long>(2, -1)));
        long long lCount = rec(to_string(max(l, 10LL) - 1), 0, 0, 1, memo);

        return rCount - lCount;
    }
};