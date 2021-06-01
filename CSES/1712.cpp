#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    cout << binPow(a, binPow(b, c, 1e9 + 6), 1e9 + 7) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}