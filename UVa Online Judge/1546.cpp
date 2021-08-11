#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int an, bn;
    cin >> an >> bn;

    vector<vector<int>> diff(an, vector<int>(an + bn));

    for (int i = 0; i < an; i++)
        cin >> diff[0][i];

    for (int level = 1; level < an; level++)
        for (int i = 0; level + i < an; i++)
            diff[level][i] = diff[level - 1][i + 1] - diff[level - 1][i];

    fill(diff.back().begin(), diff.back().end(), diff.back()[0]);

    for (int r = 0; r < bn; r++)
        for (int level = an - 2, i = 2 + r; level >= 0; level--, i++)
            diff[level][i] = diff[level][i - 1] + diff[level + 1][i - 1];
    
    for (int i = 0; i < bn; i++)
        cout << diff[0][an + i] << (i + 1 < bn ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}