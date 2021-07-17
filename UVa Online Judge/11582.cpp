#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binPow(unsigned long long x, unsigned long long p, int mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * (x % mod) % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    unsigned long long x, p;
    int mod;
    cin >> x >> p >> mod;

    vector<int> fib = { 0, 1 % mod };
    set<pair<int, int>> seen = { { fib[0], fib[1] } };

    for (int i = 2; 1; i++) {
        fib.push_back((fib[i - 2] + fib[i - 1]) % mod);
        if (seen.count({ fib[i - 1], fib[i] }))
            break;
        seen.insert({ fib[i - 1], fib[i] });
    }

    int index = binPow(x, p, seen.size());

    cout << fib[index] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}