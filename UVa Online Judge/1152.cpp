#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<vector<int>> a(4, vector<int>(n));
    for (int j = 0; j < n; j++)
        for (int i = 0; i < 4; i++)
            cin >> a[i][j];

    unordered_map<int, int> sums;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sums[a[0][i] + a[1][j]]++;

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (auto it = sums.find(-a[2][i] - a[3][j]); it != sums.end())
                res += it->second;

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}