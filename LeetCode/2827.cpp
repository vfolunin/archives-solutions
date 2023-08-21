class Solution {
    int rec(const string &s, int mod,
            int i, int balance, int remainder, int zero, int match,
            vector<vector<vector<vector<vector<int>>>>> &memo) {
        int &res = memo[i][balance + 10][remainder][zero][match];
        if (res != -1)
            return res;

        if (i == s.size())
            return res = !balance && !remainder && !zero;

        int maxDigit = match ? s[i] - '0' : 9;
        res = 0;

        for (int digit = 0; digit <= maxDigit; digit++) {
            int nextBalance = balance;
            if (digit % 2)
                nextBalance++;
            else if (!zero || digit)
                nextBalance--;

            int nextRemainder = (remainder * 10 + digit) % mod;
            int nextZero = zero && !digit;
            int nextMatch = match && digit == maxDigit;

            res += rec(s, mod, i + 1, nextBalance, nextRemainder, nextZero, nextMatch, memo);
        }

        return res;
    }

public:
    int numberOfBeautifulIntegers(int l, int r, int mod) {
        vector<vector<vector<vector<vector<int>>>>> memo(11, vector<vector<vector<vector<int>>>>(21,
            vector<vector<vector<int>>>(mod, vector<vector<int>>(2, vector<int>(2, -1)))
        ));
        int rCount = rec(to_string(r), mod, 0, 0, 0, 1, 1, memo);

        memo.assign(11, vector<vector<vector<vector<int>>>>(21,
            vector<vector<vector<int>>>(mod, vector<vector<int>>(2, vector<int>(2, -1)))
        ));
        int lCount = rec(to_string(l - 1), mod, 0, 0, 0, 1, 1, memo);

        return rCount - lCount;
    }
};