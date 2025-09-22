#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long f, fi, mod;
    vector<long long> p, pi, h;

    Hasher(const string &s) : f(29), fi(758620695), mod(1e9 + 7) {
        p.resize(s.size());
        pi.resize(s.size());
        h.resize(s.size());

        p[0] = pi[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            pi[i] = (pi[i - 1] * fi) % mod;
            h[i] = (h[i - 1] + (p[i] * (s[i] - 'a' + 1)) % mod) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l) {
            res = (res - h[l - 1] + mod) % mod;
            res = (res * pi[l]) % mod;
        }
        return res;
    }
};

bool isLess(Hasher &h, int size, string &s, int a, int b) {
    int l = 0, r = size;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (h.getHash(a, a + m - 1) == h.getHash(b, b + m - 1))
            l = m;
        else
            r = m;
    }
    return r < size && s[a + l] < s[b + l];
}

void solve() {
    int size;
    string s;
    cin >> size >> s;
    s += s;

    Hasher hasher(s);
    int res = 0;
    for (int i = 1; i < size; i++)
        if (isLess(hasher, size, s, i, res))
            res = i;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}