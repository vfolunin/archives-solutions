#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int n, int l, int r) {
    if (n <= 0 || l <= 0 || r <= 0)
        return 0;

    static vector<vector<vector<long long>>> memo(21, vector<vector<long long>>(21, vector<long long>(21, -1)));
    if (memo[n][l][r] != -1)
        return memo[n][l][r];

    if (n == 1)
        return memo[n][l][r] = (l == 1 && r == 1);

    long long res = 0;
    res += rec(n - 1, l - 1, r);
    res += rec(n - 1, l, r) * (n - 2);
    res += rec(n - 1, l, r - 1);
    return memo[n][l][r] = res;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << rec(n, l, r) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}