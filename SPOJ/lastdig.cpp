#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binPow(int x, int p, int mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * (x % mod) % mod;
    int r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << binPow(a, b, 10) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}