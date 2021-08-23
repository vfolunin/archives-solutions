#include <iostream>
#include <algorithm>
#include <vector>
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
        h[0] = s[0];

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            h[i] = (h[i - 1] + (p[i] * s[i]) % mod) % mod;
        }
    }

    unsigned long long getHash(int l, int r) {
        return ((h[r] - (l ? h[l - 1] : 0) + mod) % mod * p[p.size() - 1 - l]) % mod;
    }
};

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    Hasher h(s, 131, 1e9 + 7);
    int res = s.size();

    for (int len = 1; len <= s.size(); len++) {
        set<unsigned long long> hashes;

        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            hashes.insert(h.getHash(l, r));

            if (hashes.size() > len + 1) {
                res = min(res, r);
                break;
            }
        }
    }

    if (res == s.size())
        cout << "YES\n";
    else
        cout << "NO:" << res + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}