class Solution {
    const long long MOD = 1e9 + 7;
    map<pair<int, int>, long long> memo;

    long long count(int size, int firstDigit) {
        if (auto it = memo.find({ size, firstDigit }); it != memo.end())
            return it->second;
        long long &res = memo[{ size, firstDigit }];

        if (size == 1)
            return res = 1;

        for (int digit : { firstDigit - 1, firstDigit + 1 })
            if (0 <= digit && digit <= 9)
                res = (res + count(size - 1, digit)) % MOD;

        return res;
    }

    long long count(string &s, int i) {
        if (i + 1 == s.size())
            return 1;

        int curDigit = s[i] - '0', nextDigit = s[i + 1] - '0';
        long long res = 0;

        for (int digit : { curDigit - 1, curDigit + 1 }) {
            if (digit < 0 || digit > 9)
                continue;
            if (digit < nextDigit)
                res = (res + count(s.size() - i - 1, digit)) % MOD;
            else if (digit == nextDigit)
                res = (res + count(s, i + 1)) % MOD;
        }

        return res;
    }

    long long count(string &s) {
        long long res = 0;

        for (int size = 1; size < s.size(); size++)
            for (int firstDigit = 1; firstDigit <= 9; firstDigit++)
                res = (res + count(size, firstDigit)) % MOD;

        for (int firstDigit = 1; firstDigit < s[0] - '0'; firstDigit++)
            res = (res + count(s.size(), firstDigit)) % MOD;

        res = (res + count(s, 0)) % MOD;

        return res;
    }

    bool isStepping(string &s) {
        for (int i = 1; i < s.size(); i++)
            if (abs(s[i - 1] - s[i]) != 1)
                return 0;
        return 1;
    }

public:
    int countSteppingNumbers(string &l, string &r) {
        return ((count(r) - count(l) + isStepping(l)) % MOD + MOD) % MOD;
    }
};