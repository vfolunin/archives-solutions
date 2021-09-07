#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (long long &x : a)
        cin >> x;

    vector<vector<long long>> maxCost(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
        maxCost[i][i] = n * a[i];

    for (int len = 2; len <= n; len++)
        for (int l = 0, r = len - 1; r < n; l++, r++)
            maxCost[l][r] = max((n - len + 1) * a[l] + maxCost[l + 1][r], (n - len + 1) * a[r] + maxCost[l][r - 1]);

    cout << maxCost[0][n - 1];
}