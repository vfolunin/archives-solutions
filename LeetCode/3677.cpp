class Solution {
    string toBin(long long n) {
        string res;
        for (; n > 1; n /= 2)
            res += n % 2 + '0';
        res += n + '0';
        reverse(res.begin(), res.end());
        return res;
    }

    long long toDec(const string &s) {
        long long res = 0;
        for (char c : s)
            res = res * 2 + c - '0';
        return res;
    }

public:
    int countBinaryPalindromes(long long n) {
        if (n <= 1)
            return n + 1;
            
        string s = toBin(n);

        int res = 0;

        for (int size = 1; size * 2 < s.size(); size++)
            res += 1 << (size - 1);
        for (int size = 0; size * 2 + 1 < s.size(); size++)
            res += 1 << (size ? size : 1);

        string l = s.substr(0, s.size() / 2);
        string r(l.rbegin(), l.rend());
        if (s.size() % 2)
            l += s[s.size() / 2];
        if (l.size() > 1)
            res += toDec(l.substr(1));

        res += l + r <= s;

        return res;
    }
};