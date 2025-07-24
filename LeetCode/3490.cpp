class Solution {
    int rec(const string &s, int i, bool isPrefixOfS, bool hasLeadingZero, int product, int sum,
            map<tuple<int, bool, bool, int, int>, int> &memo) {
        tuple key = { i, isPrefixOfS, hasLeadingZero, product, sum };
        if (memo.count(key))
            return memo[key];
        int &res = memo[key];

        if (i == s.size())
            return res = sum && product % sum == 0;

        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;
        for (int digit = 0; digit <= maxDigit; digit++) {
            bool nextIsPrefixOfS = isPrefixOfS && digit == s[i] - '0';
            bool nextHasLeadingZero = hasLeadingZero && !digit;
            int nextProduct = nextHasLeadingZero ? product : product * digit;
            int nextSum = sum + digit;
            res += rec(s, i + 1, nextIsPrefixOfS, nextHasLeadingZero, nextProduct, nextSum, memo);
        }

        return res;
    }

public:
    int beautifulNumbers(int l, int r) {
        map<tuple<int, bool, bool, int, int>, int> memo;
        int rCount = rec(to_string(r), 0, 1, 1, 1, 0, memo);

        memo.clear();
        int lCount = rec(to_string(l - 1), 0, 1, 1, 1, 0, memo);

        return rCount - lCount;
    }
};