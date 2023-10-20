#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    Hasher h1(s), h2({ s.rbegin(), s.rend() });

    for (int len = 1; len <= s.size(); len++) {
        int l = 0, r = len + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (h1.getHash(0, m - 1) == h2.getHash(s.size() - len, s.size() - len + m - 1))
                l = m;
            else
                r = m;
        }
        cout << l << " ";
    }
}