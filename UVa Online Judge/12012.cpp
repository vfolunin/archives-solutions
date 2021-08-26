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

void solve(int test) {
    string s;
    cin >> s;

    Hasher hasher(s);
    vector<int> res(s.size() + 1);

    for (int len = 1; len <= s.size(); len++) {
        vector<int> countTo(s.size());
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (0 <= l - len && hasher.getHash(l - len, r - len) == hasher.getHash(l, r))
                countTo[r] = countTo[r - len] + 1;
            else
                countTo[r] = 1;
            res[countTo[r]] = max(res[countTo[r]], len);
        }
    }

    cout << "Case #" << test << ": ";
    for (int i = 1; i <= s.size(); i++)
        cout << res[i] * i << (i + 1 <= s.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}