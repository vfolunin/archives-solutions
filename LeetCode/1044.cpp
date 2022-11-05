struct Hasher {
    long long x, mod;
    vector<long long> p, h;

    Hasher(const string &s, long long x, long long mod) : x(x), mod(mod) {
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
    bool can(Hasher &h1, Hasher &h2, int len, string *s) {
        set<pair<long long, long long>> seen;
        for (int l = 0, r = len - 1; r < h1.h.size(); l++, r++) {
            pair<long long, long long> hash = { h1.getHash(l, r), h2.getHash(l, r) };
            if (seen.count(hash)) {
                if (s)
                    *s = s->substr(l, len);
                return 1;
            }
            seen.insert(hash);
        }
        return 0;
    }
    
public:
    string longestDupSubstring(string &s) {
        Hasher h1(s, 29, 1e9 + 7), h2(s, 31, 1e9 + 9);
        
        int l = 0, r = s.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(h1, h2, m, 0))
                l = m;
            else
                r = m;
        }
        
        if (l)
            can(h1, h2, l, &s);
        else
            s = "";
        return s;
    }
};