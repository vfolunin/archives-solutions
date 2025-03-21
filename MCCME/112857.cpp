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

bool isLess(string &s, Hasher &hasher, int l1, int r1, int l2, int r2) {
    int l = 0, r = min(r1 - l1 + 1, r2 - l2 + 1) + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (hasher.getHash(l1, l1 + m - 1) == hasher.getHash(l2, l2 + m - 1))
            l = m;
        else
            r = m;
    }
    return l2 + l <= r2 && (l1 + l > r1 || s[l1 + l] < s[l2 + l]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    Hasher hasher(s);

    int resL = 0, resR = s.size() - 1;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l; r < s.size(); r++) {
            if (isLess(s, hasher, resL, resR, l, r)) {
                resL = l;
                resR = r;
            }
        }
    }

    cout << s.substr(resL, resR - resL + 1);
}