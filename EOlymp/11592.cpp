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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    Hasher h1(s), h2({ s.rbegin(), s.rend() });

    const long long MOD = 1e9 + 7;
    vector<long long> ways(s.size() + 1);
    ways[0] = 1;

    for (int size = 1; size <= s.size(); size++)
        for (int partSize = 1; partSize <= size; partSize++)
            if (h1.getHash(size - partSize, size - 1) == h2.getHash(s.size() - size, s.size() - size + partSize - 1))
                ways[size] = (ways[size] + ways[size - partSize]) % MOD;

    cout << ways.back();
}