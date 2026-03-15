class Solution {
    void recUp(long long value, unordered_set<long long> &values) {
        if (value)
            values.insert(value);
        for (int digit = value % 10 + 1; digit <= 9; digit++)
            recUp(value * 10 + digit, values);
    }

    void recDown(long long value, unordered_set<long long> &values) {
        if (value)
            values.insert(value);
        for (int digit = value % 10 - 1; digit >= 0; digit--)
            recDown(value * 10 + digit, values);
    }

    int digitSum(long long n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    long long rec(const string &s, int i, int digitSum, bool isPrefixOfS, unordered_set<long long> &values, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[i][digitSum][isPrefixOfS];
        if (res != -1)
            return res;

        if (i == s.size())
            return values.count(digitSum);

        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;

        for (int digit = 0; digit <= maxDigit; digit++) {
            int nextDigitSum = digitSum + digit;
            bool nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

            res += rec(s, i + 1, nextDigitSum, nextIsPrefixOfS, values, memo);
        }

        return res;
    }

public:
    long long countFancy(long long l, long long r) {
        unordered_set<long long> values;
        recUp(0, values);
        for (int value = 9; value; value--)
            recDown(value, values);
        
        long long res = 0;
        for (long long value : values)
            res += l <= value && value <= r && !values.count(digitSum(value));
        
        vector memo(20, vector(200, vector<long long>(2, -1)));
        res += rec(to_string(r), 0, 0, 1, values, memo);
        memo.assign(20, vector(200, vector<long long>(2, -1)));
        res -= rec(to_string(l - 1), 0, 0, 1, values, memo);

        return res;
    }
};