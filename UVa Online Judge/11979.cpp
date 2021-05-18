#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> columns(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> columns[j][i];

    long long res = 0;
    for (vector<int> &column : columns) {
        sort(column.begin(), column.end());
        for (int i = 0; i < n; i++)
            res += abs(column[i] - i);
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}