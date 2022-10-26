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
    int getCommonPrefix(Hasher &h, int from) {
        int l = 0, r = h.p.size() - from + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (h.getHash(0, m - 1) == h.getHash(from, from + m - 1))
                l = m;
            else
                r = m;
        }
        return l;
    }
    
public:
    long long sumScores(string &s) {
        Hasher h(s);
        long long res = 0;
        for (int i = 0; i < s.size(); i++)
            res += getCommonPrefix(h, i);
        return res;
    }
};