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
        h[0] = s[0] - 'A' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + s[i] - 'A' + 1) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    Hasher hasher(s);
    vector<int> res(s.size() + 1);
    for (int size = 1; size <= s.size(); size++)
        for (int partSize = 2; partSize <= size; partSize += 2)
            if (hasher.getHash(size - partSize, size - partSize / 2 - 1) == hasher.getHash(size - partSize / 2, size - 1))
                res[size] = max(res[size], res[size - partSize] + partSize);

    cout << *max_element(res.begin(), res.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}