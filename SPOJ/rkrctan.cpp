#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    const long long MOD = 1e9 + 7;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    d %= MOD;
    a = a * b % MOD;
    c = c * d % MOD;

    cout << (a - c + MOD) % MOD << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}