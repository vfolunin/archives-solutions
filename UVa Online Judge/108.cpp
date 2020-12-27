#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum(vector<vector<int>> &p, int i1, int j1, int i2, int j2) {
    int res = p[i2][j2];
    if (i1)
        res -= p[i1 - 1][j2];
    if (j1)
        res -= p[i2][j1 - 1];
    if (i1 && j1)
        res += p[i1 - 1][j1 - 1];
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            if (i)
                p[i][j] += p[i - 1][j];
            if (j)
                p[i][j] += p[i][j - 1];
            if (i && j)
                p[i][j] -= p[i - 1][j - 1];
        }
    }

    int res = -1e9;

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            for (int i2 = i1; i2 < n; i2++)
                for (int j2 = j1; j2 < n; j2++)
                    res = max(res, sum(p, i1, j1, i2, j2));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}