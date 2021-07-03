#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, vector<vector<int>> &memo) {
    if (!memo[n].empty())
        return;

    if (n == 1) {
        memo[n] = { 0 };
        return;
    }

    memo[n].resize(n);
    rec(n / 2, memo);
    for (int i = 0; i < n / 2; i++)
        memo[n][i] = memo[n / 2][i] * 2 + 1;

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++)
            memo[n][n / 2 + i] = memo[n / 2][i] * 2;
    } else {
        rec(n / 2 + 1, memo);
        for (int i = 0; i < n / 2; i++)
            memo[n][n / 2 + i] = memo[n / 2 + 1][i] * 2;
    }
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<vector<int>> memo(10001);
    rec(n, memo);

    cout << n << ": ";
    for (int i = 0; i < n; i++)
        cout << memo[n][i] << (i + 1 < n ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}