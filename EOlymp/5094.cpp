#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

struct Hasher {
    long long x, mod;
    vector<long long> p, h;

    Hasher(const string &s, long long x = 31, long long mod = 1e9 + 7) : x(x), mod(mod) {
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

bool can(vector<Hasher> hashers, int size) {
    unordered_set<long long> hashes;
    for (int l = 0, r = size - 1; r < hashers[0].h.size(); l++, r++)
        hashes.insert(hashers[0].getHash(l, r));

    for (int i = 1; !hashes.empty() && i < hashers.size(); i++) {
        unordered_set<long long> nextHashes;
        for (int l = 0, r = size - 1; r < hashers[i].h.size(); l++, r++) {
            long long hash = hashers[i].getHash(l, r);
            if (hashes.count(hash))
                nextHashes.insert(hash);
        }
        hashes.swap(nextHashes);
    }

    return !hashes.empty();
}

int getFrom(vector<Hasher> hashers, int size) {
    unordered_map<long long, vector<int>> from;
    for (int l = 0, r = size - 1; r < hashers[0].h.size(); l++, r++)
        from[hashers[0].getHash(l, r)] = { l };

    for (int i = 1; i < hashers.size(); i++) {
        unordered_map<long long, vector<int>> nextFrom;
        for (int l = 0, r = size - 1; r < hashers[i].h.size(); l++, r++) {
            long long hash = hashers[i].getHash(l, r);
            if (from.count(hash)) {
                nextFrom[hash] = from[hash];
                nextFrom[hash].push_back(l);
            }
        }
        from.swap(nextFrom);
    }

    return from.begin()->second[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    vector<Hasher> hashers;
    int l = 0, r = 1e9;

    for (string &s : a) {
        cin >> s;

        hashers.push_back(Hasher(s));
        r = min<int>(r, s.size() + 1);
    }

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(hashers, m))
            l = m;
        else
            r = m;
    }

    cout << a[0].substr(getFrom(hashers, l), l);
}