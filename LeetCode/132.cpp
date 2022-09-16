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
    int minCut(string &s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        Hasher hs(s), hr(r);
        
        vector<int> res(s.size() + 1, 1e9);
        res[0] = 0;
        
        for (int size = 1; size <= s.size(); size++)
            for (int l = 0, r = size - 1; l <= r; l++)
                if (hs.getHash(l, r) == hr.getHash(s.size() - 1 - r, s.size() - 1 - l))
                    res[size] = min(res[size], res[size - (r - l + 1)] + 1);
        
        return res.back() - 1;
    }
};