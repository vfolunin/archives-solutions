#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long mod;
    vector<long long> p, h;

    Hasher(const string &s, long long factor = 31, long long mod = 1e9 + 7) : mod(mod) {
        p.push_back(1);
        for (int i = 1; i < s.size(); i++)
            p.push_back(p[i - 1] * factor % mod);

        h.push_back(s[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
            h.push_back((h[i - 1] * factor % mod + s[i] - 'a' + 1) % mod);
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

    DoubleHasher(const string &s) : h1(s), h2(s, 29, 1e9 + 9) {}

    pair<long long, long long> getHash(int l, int r) {
        return { h1.getHash(l, r), h2.getHash(l, r) };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    DoubleHasher hasher(s);
    set<pair<long long, long long>> hashes;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            hashes.insert(hasher.getHash(l, r));

    cout << hashes.size();
}