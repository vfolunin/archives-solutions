#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int i, int j, int n, vector<vector<long long>> &memo) {
    if (memo[i][j] != -1)
        return memo[i][j];

    long long &res = memo[i][j];
    if (i >= j) {
        long long res1 = 0, res2 = 0;
        for (int k = i + 1; k <= n; k++)
            res1 = max(res1, rec(k, 1, n, memo) + rec(k, j, n, memo));
        for (int k = 1; k < j; k++)
            res2 = max(res2, rec(i, k, n, memo) + rec(n, k, n, memo));
        res = res1 + res2;
    } else {
        for (int k = i; k < j; k++)
            res = max(res, rec(i, k, n, memo) + rec(k + 1, j, n, memo));
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<vector<long long>> memo(n + 1, vector<long long>(n + 1, -1));
    cin >> memo[n][1];

    cout << rec(1, n, n, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}