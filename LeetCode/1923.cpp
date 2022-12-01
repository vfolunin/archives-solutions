struct Hasher {
    long long x, mod;
    vector<long long> p, h;
    
    Hasher() {}

    Hasher(const vector<int> &a, long long x, long long mod) : x(x), mod(mod) {
        p.resize(a.size());
        h.resize(a.size());

        p[0] = 1;
        h[0] = a[0] + 1;

        for (int i = 1; i < a.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + a[i] + 1) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

bool can(vector<Hasher> &ha, vector<Hasher> &hb, int len) {
    unordered_set<long long> hashes;
    for (int l = 0, r = len - 1; r < ha[0].p.size(); l++, r++)
        hashes.insert(ha[0].getHash(l, r) * 1000000 + hb[0].getHash(l, r));
    
    for (int i = 1; i < ha.size(); i++) {
        unordered_set<long long> curHashes;
        
        for (int l = 0, r = len - 1; r < ha[i].p.size(); l++, r++) {
            long long hash = ha[i].getHash(l, r) * 1000000 + hb[i].getHash(l, r);
            if (hashes.count(hash))
                curHashes.insert(hash);
        }
        
        if (curHashes.empty())
            return 0;
        
        hashes.swap(curHashes);
    }
    
    return 1;
}

class Solution {
public:
    int longestCommonSubpath(int vertexCount, vector<vector<int>> &paths) {
        sort(paths.begin(), paths.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });
        
        vector<Hasher> ha(paths.size()), hb(paths.size());
        for (int i = 0; i < paths.size(); i++) {
            ha[i] = Hasher(paths[i], 2, 1e9 + 7);
            hb[i] = Hasher(paths[i], 3, 1e9 + 9);
        }
        
        int l = 0, r = paths[0].size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(ha, hb, m))
                l = m;
            else
                r = m;
        }        
        return l;
    }
};