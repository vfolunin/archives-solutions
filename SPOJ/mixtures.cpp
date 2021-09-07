#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> color(n);
    for (int &x : color)
        cin >> x;

    vector<vector<int>> minSmoke(n, vector<int>(n));
    vector<vector<int>> minColor(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        minColor[i][i] = color[i];

    for (int i = 0; i + 1 < n; i++) {
        minSmoke[i][i + 1] = color[i] * color[i + 1];
        minColor[i][i + 1] = (color[i] + color[i + 1]) % 100;
    }

    for (int len = 3; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++, r++) {
            minSmoke[l][r] = 1e9;

            for (int m = l; m < r; m++) {
                int curSmoke = minSmoke[l][m] + minColor[l][m] * minColor[m + 1][r] + minSmoke[m + 1][r];
                int curColor = (minColor[l][m] + minColor[m + 1][r]) % 100;

                if (minSmoke[l][r] > curSmoke) {
                    minSmoke[l][r] = curSmoke;
                    minColor[l][r] = curColor;
                }
            }
        }
    }

    cout << minSmoke[0][n - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}