#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<vector<int>> p, int i1, int j1, int i2, int j2) {
    int res = p[i2][j2];
    if (i1)
        res -= p[i1 - 1][j2];
    if (j1)
        res -= p[i2][j1 - 1];
    if (i1 && j1)
        res += p[i1 - 1][j1 - 1];
    return res;
}

void solve() {
    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    vector<vector<int>> p(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < w; j++) {
            p[i][j] = row[j] - 'a';
            if (i)
                p[i][j] += p[i - 1][j];
            if (j)
                p[i][j] += p[i][j - 1];
            if (i && j)
                p[i][j] -= p[i - 1][j - 1];
        }
    }

    cout << h << " " << w << " " << queryCount << "\n";
    for (int qi = 0; qi < queryCount; qi++) {
        int ic, jc;
        cin >> ic >> jc;

        int size = 1;
        while (1) {
            int i1 = ic - size, i2 = ic + size;
            int j1 = jc - size, j2 = jc + size;
            if (i1 < 0 || i2 >= h || j1 < 0 || j2 >= w)
                break;
            if (sum(p, i1, j1, i2, j2) != 0 && sum(p, i1, j1, i2, j2) != (i2 - i1 + 1) * (j2 - j1 + 1))
                break;
            size++;
        }

        cout << 2 * size - 1 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}