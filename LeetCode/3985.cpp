struct Hasher {
    long long x, mod;
    vector<long long> p, h;

    Hasher(const vector<int> &a, long long x = 1e9 + 7, long long mod = 1e9 + 33) : x(x), mod(mod) {
        p.resize(a.size());
        h.resize(a.size());

        p[0] = 1;
        h[0] = a[0];

        for (int i = 1; i < a.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + a[i]) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

struct PalindromeChecker {
    Hasher hl, hr;

    PalindromeChecker(const vector<int> &a) : hl(a), hr({ a.rbegin(), a.rend() }) {}

    bool isPalindrome(int l, int r) {
        return hl.getHash(l, r) == hr.getHash(hr.h.size() - 1 - r, hr.h.size() - 1 - l);
    }
};

struct PrefixSums {
    vector<long long> p;

    PrefixSums(vector<int> &a) : p(a.begin(), a.end()) {
        partial_sum(p.begin(), p.end(), p.begin());
    }

    long long getSum(int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
};

class Solution {
public:
    long long getSum(vector<int> &a) {
        PalindromeChecker palindromeChecker(a);
        PrefixSums prefixSums(a);
        long long res = 0;

        for (int i = 0; i < a.size(); i++) {
            int l = 0, r = min<int>(i, a.size() - 1 - i) + 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (palindromeChecker.isPalindrome(i - m, i + m))
                    l = m;
                else
                    r = m;
            }
            res = max(res, prefixSums.getSum(i - l, i + l));
        }

        for (int i = 0; i + 1 < a.size(); i++) {
            int l = -1, r = min<int>(i, a.size() - 2 - i) + 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (palindromeChecker.isPalindrome(i - m, i + 1 + m))
                    l = m;
                else
                    r = m;
            }
            if (l != -1)
                res = max(res, prefixSums.getSum(i - l, i + 1 + l));
        }

        return res;
    }
};