struct Hasher {
    long long x = 31, mod = 1e9 + 7;
    vector<long long> p, h;

    Hasher(const string &s) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - '0' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + s[i] - '0' + 1) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

bool lessEqual(string &s, Hasher &h, int a, int b, int size) {
    int l = 0, r = size + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (h.getHash(a, a + m - 1) == h.getHash(b, b + m - 1))
            l = m;
        else
            r = m;
    }
    return l == size || s[a + l] < s[b + l];
}

class Solution {
    const long long MOD = 1e9 + 7;

    long long rec(int len, int lastLen, string &s, Hasher &h, vector<vector<long long>> &memo) {
        long long &res = memo[len][lastLen];
        if (res != -1)
            return res;

        if (!len)
            return res = 1;

        if (!lastLen)
            return res = 0;
        
        res = rec(len, lastLen - 1, s, h, memo);
        if (len >= lastLen && s[len - lastLen] != '0') {
            if (len >= 2 * lastLen && lessEqual(s, h, len - 2 * lastLen, len - lastLen, lastLen))
                res = (res + rec(len - lastLen, lastLen, s, h, memo)) % MOD;
            else
                res = (res + rec(len - lastLen, lastLen - 1, s, h, memo)) % MOD;
        }

        return res;
    }

public:
    int numberOfCombinations(string s) {
        Hasher h(s);
        vector<vector<long long>> memo(s.size() + 1, vector<long long>(s.size() + 1, -1));
        return rec(s.size(), s.size(), s, h, memo);
    }
};