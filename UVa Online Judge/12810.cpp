#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 9, INV = 500000005;

void solve() {
    int n;
    cin >> n;

    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        res = (res * (x * 2 + 1)) % MOD;
    }
    res = (res - 1) * INV % MOD;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}