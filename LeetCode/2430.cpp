struct Hasher {
    long long x = 31, mod = 1e9 + 7;
    vector<long long> p, h;

    Hasher(const string &s) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + s[i] - 'a' + 1) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

class Solution {
public:
    int deleteString(string &s) {
        Hasher h(s);
        
        vector<int> res(s.size(), 1);
        
        for (int i = (int)s.size() - 2; i >= 0; i--)
            for (int len = 1; i + 2 * len <= s.size(); len++)
                if (h.getHash(i, i + len - 1) == h.getHash(i + len, i + 2 * len - 1))
                    res[i] = max(res[i], res[i + len] + 1);
        
        return res[0];
    }
};