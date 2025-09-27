#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factPower(long long f, int p) {
    long long res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;

    long long res = 1e18;
    for (auto &[p, k] : vector<pair<int, int>>{ { 2, 2 }, { 3, 1 } })
        res = min(res, factPower(n, p) / k);

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