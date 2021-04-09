#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long f, mod;
    vector<long long> p, h;

    Hasher(string &s, long long f, long long mod) : f(f), mod(mod) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'A' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            h[i] = (h[i - 1] + (p[i] * (s[i] - 'A' + 1)) % mod) % mod;
        }
    }

    long long getHash(int l, int r) {
        return ((h[r] - (l ? h[l - 1] : 0) + mod) % mod * p[p.size() - 1 - l]) % mod;
    }
};

bool can(Hasher &h1, Hasher &h2, int size, int len) {
    set<pair<long long, long long>> hashes;
    for (int l = 0, r = len - 1; r < size; l++, r++) {
        long long v1 = h1.getHash(l, r), v2 = h2.getHash(l, r);
        if (hashes.count({v1, v2}))
            return 1;
        hashes.insert({v1, v2});
    }
    return 0;
}

void solve() {
    string s;
    cin >> s;

    Hasher h1(s, 29, 1e9 + 7), h2(s, 31, 1e9 + 9);

    int l = 0, r = s.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(h1, h2, s.size(), m))
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}