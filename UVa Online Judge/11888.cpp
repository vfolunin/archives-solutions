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
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            h[i] = (h[i - 1] + (p[i] * (s[i] - 'a' + 1)) % mod) % mod;
        }
    }

    unsigned long long getHash(int l, int r) {
        return ((h[r] - (l ? h[l - 1] : 0) + mod) % mod * p[p.size() - 1 - l]) % mod;
    }
};

void solve() {
    string s;
    cin >> s;
    Hasher h1(s, 29, 1e9 + 7);

    reverse(s.begin(), s.end());
    Hasher h2(s, 29, 1e9 + 7);

    for (int a = 1, b = s.size() - 1; b > 0; a++, b--) {
        if (h1.getHash(0, a - 1) == h2.getHash(b, b + a - 1) &&
            h1.getHash(a, a + b - 1) == h2.getHash(0, b - 1)) {
            cout << "alindrome\n";
            return;
        }
    }

    if (h1.getHash(0, s.size() - 1) == h2.getHash(0, s.size() - 1))
        cout << "palindrome\n";
    else
        cout << "simple\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}