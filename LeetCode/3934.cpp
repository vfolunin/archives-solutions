struct Hasher {
    long long mod;
    vector<long long> p, h;

    Hasher(const vector<int> &a, long long factor = 1e5 + 1, long long mod = 1e9 + 7) : mod(mod) {
        p.push_back(1);
        for (int i = 1; i < a.size(); i++)
            p.push_back(p[i - 1] * factor % mod);

        h.push_back(a[0]);
        for (int i = 1; i < a.size(); i++)
            h.push_back((h[i - 1] * factor % mod + a[i]) % mod);
    }

    int size() {
        return h.size();
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
        unordered_map<long long, int> count;
        for (int l = 0, r = size - 1; r < hasher.size(); l++, r++)
            count[hasher.getHash(l, r)]++;
        
        for (auto &[_, count] : count)
            if (count == 1)
                return 1;
        return 0;
    }

public:
    int smallestUniqueSubarray(vector<int> &a) {
        Hasher hasher(a);
        int l = 0, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(hasher, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};