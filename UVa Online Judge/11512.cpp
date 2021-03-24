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

void solve() {
    string s;
    cin >> s;

    Hasher hasher(s, 29, 1e9 + 7);

    int l = 0, r = s.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;

        set<unsigned long long> hashes;
        for (int p = 0, q = m - 1; q < s.size(); p++, q++)
            hashes.insert(hasher.getHash(p, q));

        if (hashes.size() == s.size() - m + 1)
            r = m;
        else
            l = m;
    }

    if (!l) {
        cout << "No repetitions found!\n";
        return;
    }

    map<string, unsigned long long> reps;

    map<unsigned long long, int> hashes;
    for (int i = 0; i + l <= s.size(); i++) {
        unsigned long long hash = hasher.getHash(i, i + l - 1);
        if (hashes[hash])
            reps[s.substr(i, l)] = hash;
        hashes[hash]++;
    }

    cout << reps.begin()->first << " " << hashes[reps.begin()->second] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}