class Solution {
    string fromDec(long long n, int base) {
        static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;
        while (n >= base) {
            res += DIGITS[n % base];
            n /= base;
        }
        res += DIGITS[n];
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string concatHex36(int n) {
        return fromDec(n * n, 16) + fromDec(n * n * n, 36);
    }
};