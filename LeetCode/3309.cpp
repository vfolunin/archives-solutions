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

    long long toDec(vector<string> &b, int base) {
        static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        long long res = 0;
        for (string &s : b)
            for (char c : s)
                res = res * base + DIGITS.find(c);
        return res;
    }

public:
    int maxGoodNumber(vector<int> &a) {
        vector<string> b(a.size());
        for (int i = 0; i < a.size(); i++)
            b[i] = fromDec(a[i], 2);
        sort(b.begin(), b.end());

        long long res = 0;
        do {
            res = max(res, toDec(b, 2));
        } while (next_permutation(b.begin(), b.end()));
        return res;
    }
};