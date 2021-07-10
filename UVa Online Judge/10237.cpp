#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int squares(int i) {
    if (i % 2)
        return i / 4 * 2 + 1;
    else
        return (i - 1) / 4 * 2 + 2;
}

long long bishopPlacements(int n, int k) {
    if (k > 2 * n - 1)
        return 0;

    vector<vector<long long>> d(n * 2, vector<long long>(k + 1));
    for (int i = 0; i < n * 2; i++)
        d[i][0] = 1;
    d[1][1] = 1;

    for (int i = 2; i < n * 2; ++i)
        for (int j = 1; j <= k; ++j)
            d[i][j] = d[i - 2][j] + d[i - 2][j - 1] * (squares(i) - j + 1);

    long long res = 0;
    for (int i = 0; i <= k; ++i)
        res += d[n * 2 - 1][i] * d[n * 2 - 2][k - i];
    return res;
}

bool solve() {
    int n, k;
    if (!(cin >> n >> k) || !n && !k)
        return 0;

    cout << bishopPlacements(n, k) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}