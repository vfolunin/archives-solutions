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
    bool can(Hasher &hasher, int size) {
        unordered_set<long long> seen;
        for (int l = 0, r = size - 1; r < hasher.p.size(); l++, r++) {
            long long hash = hasher.getHash(l, r);
            if (seen.count(hash))
                return 1;
            seen.insert(hash);
        }
        return 0;
    }

public:
    int longestRepeatingSubstring(string &s) {
        Hasher hasher(s);

        int l = 0, r = s.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(hasher, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};