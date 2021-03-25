#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;

    if (n < 0 && m < 0)
        return 0;

    if (m > n) {
        cout << "0\n";
        return 1;
    }

    vector<vector<vector<long long>>> ways(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2)));
    ways[1][0][0] = 1;
    ways[1][1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            ways[i][j][0] += ways[i - 1][j][0];
            if (j < i)
                ways[i][j][0] += ways[i - 1][j + 1][1];
            if (j > 0)
                ways[i][j][1] = ways[i - 1][j - 1][0] + ways[i - 1][j - 1][1];
        }
    }

    cout << ways[n][m][0] + ways[n][m][1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}