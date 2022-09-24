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
    int distinctEchoSubstrings(string &s) {
        Hasher h(s);
        unordered_set<long long> hashes;
        
        for (int len = 1; len * 2 <= s.size(); len++)
            for (int i = 0; i + len * 2 <= s.size(); i++)
                if (h.getHash(i, i + len - 1) == h.getHash(i + len, i + 2 * len - 1))
                    hashes.insert(h.getHash(i, i + len - 1));
        
        return hashes.size();
    }
};