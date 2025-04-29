struct BigInteger {
    vector<int> digits;
    inline static const int BASE = 1e9;
    inline static const int DIGIT_WIDTH = 9;

    inline int digit(int index) const {
        return index < digits.size() ? digits[index] : 0;
    }

    inline int &digit(int index) {
        if (digits.size() <= index)
            digits.resize(index + 1);
        return digits[index];
    }

    inline void removeZeros() {
        while (!digits.empty() && !digits.back())
            digits.pop_back();
    }

    BigInteger(long long value = 0) {
        for (; value; value /= BASE)
            digits.push_back(value % BASE);
    }

    BigInteger(const string &s) {
        for (int r = s.size() - 1; r >= 0; r -= DIGIT_WIDTH) {
            int l = max(r - DIGIT_WIDTH + 1, 0);
            digits.push_back(stoi(s.substr(l, r - l + 1)));
        }
        removeZeros();
    }

    bool operator >= (const BigInteger &that) const {
        if (digits.size() != that.digits.size())
            return digits.size() > that.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--)
            if (digit(i) != that.digit(i))
                return digit(i) > that.digit(i);
        return 1;
    }

    BigInteger operator / (int that) const {
        BigInteger res;
        for (int i = digits.size() - 1, carry = 0; i >= 0; i--) {
            long long cur = 1LL * carry * BASE + digit(i);
            res.digit(i) = cur / that;
            carry = cur % that;
        }
        res.removeZeros();
        return res;
    }

    int operator % (int that) const {
        long long res = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
            res = (res * BASE + digit(i)) % that;
        return res;
    }

    string fromDec(int base) {
        BigInteger value = *this;
        string res;
        while (value >= base) {
            res += value % base + '0';
            value = value / base;
        }
        res += value.digit(0) + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
    const long long MOD = 1e9 + 7;

    long long rec(const string &s, int i, int from, bool isPrefixOfS, int base, vector<vector<vector<long long>>> &memo) {
        if (i == s.size())
            return 1;

        long long &res = memo[i][from][isPrefixOfS];
        if (res != -1)
            return res;

        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : base - 1;

        for (int digit = from; digit <= maxDigit; digit++) {
            int nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;
            res = (res + rec(s, i + 1, digit, nextIsPrefixOfS, base, memo)) % MOD;
        }

        return res;
    }

public:
    int countNumbers(string &l, string &r, int base) {
        l = BigInteger(l).fromDec(base);
        r = BigInteger(r).fromDec(base);
        l = string(r.size() - l.size(), '0') + l;

        vector memo(l.size(), vector(base, vector<long long>(2, -1)));
        long long lCount = rec(l, 0, 0, 1, base, memo);

        memo.assign(r.size(), vector(base, vector<long long>(2, -1)));
        long long rCount = rec(r, 0, 0, 1, base, memo);

        return ((rCount - lCount + is_sorted(l.begin(), l.end())) % MOD + MOD) % MOD;
    }
};