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
    string convertDateToBinary(string &s) {
        return fromDec(stoi(s.substr(0, 4)), 2) + "-" +
               fromDec(stoi(s.substr(5, 2)), 2) + "-" +
               fromDec(stoi(s.substr(8, 2)), 2);
    }
};