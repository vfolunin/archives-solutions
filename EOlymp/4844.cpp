#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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

struct DoubleHasher {
    Hasher h1, h2;

    DoubleHasher(const string &s) : h1(s), h2(s, 37, 1e9 + 9) {}

    pair<long long, long long> getHash(int l, int r) {
        return { h1.getHash(l, r), h2.getHash(l, r) };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    int len;
    cin >> a >> b >> len;

    if (!len) {
        cout << "YES";
        return 0;
    }

    DoubleHasher ha(a), hb(b);
    set<pair<long long, long long>> hashes;
    for (int l = 0, r = len - 1; r < ha.h1.h.size(); l++, r++)
        hashes.insert(ha.getHash(l, r));

    for (int l = 0, r = len - 1; r < hb.h1.h.size(); l++, r++) {
        if (hashes.count(hb.getHash(l, r))) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}