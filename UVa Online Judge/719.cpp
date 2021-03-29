#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    unsigned long long f, mod;
    vector<unsigned long long> p, h;

    Hasher(string &s, int f, int mod) : f(f), mod(mod) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'A' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            h[i] = (h[i - 1] + (p[i] * (s[i] - 'A' + 1)) % mod) % mod;
        }
    }

    unsigned long long getHash(int l, int r) {
        return ((h[r] - (l ? h[l - 1] : 0) + mod) % mod * p[p.size() - 1 - l]) % mod;
    }
};

bool compare(Hasher &h, string &s, int fromA, int fromB, int len) {
    int l = 0, r = len;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (h.getHash(fromA, fromA + m - 1) == h.getHash(fromB, fromB + m - 1))
            l = m;
        else
            r = m;
    }
    return r < len &&s[fromA + r - 1] < s[fromB + r - 1];
}

void solve() {
    string s;
    cin >> s;

    int len = s.size();
    s += s;
    Hasher h(s, 29, 1e9 + 7);

    int res = 0;
    for (int i = 1; i < len; i++)
        if (compare(h, s, i, res, len))
            res = i;

    cout << res + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}