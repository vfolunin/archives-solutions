struct Hasher {
    long long x = 11, mod = 1e9 + 7;
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

struct Counter {
    vector<int> count;
    unordered_map<int, int> counts;

    Counter() : count(10) {
        counts[0] = 10;
    }

    void add(char c, int delta) {
        if (!--counts[count[c - '0']])
            counts.erase(count[c - '0']);
        count[c - '0'] += delta;
        counts[count[c - '0']]++;
    }

    bool isOk() {
        return counts.size() - counts.count(0) == 1;
    }
};

class Solution {
public:
    int equalDigitFrequency(string &s) {
        Hasher hasher(s);
        unordered_set<long long> hashes;

        for (int l = 0; l < s.size(); l++) {
            Counter counter;
            for (int r = l; r < s.size(); r++) {
                counter.add(s[r], 1);
                if (counter.isOk())
                    hashes.insert(hasher.getHash(l, r));
            }
        }

        return hashes.size();
    }
};