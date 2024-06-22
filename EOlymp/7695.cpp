#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    const long long MOD = 1e9 + 7;
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i % MOD;
    res = (res + MOD - 1) % MOD;

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