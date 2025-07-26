#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    const int MOD = 1e9 + 7;
    long long res = 1;

    for (int i = 0; i < h + w; i++)
        res = res * 3 % MOD;

    for (int i = 0; i < h * w; i++)
        res = res * 2 % MOD;

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