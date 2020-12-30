#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve(vector<vector<int>> &g) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int res = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            res += g[i][j];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> g(501, vector<int>(501));
    for (int i = 0; i < 501; i++)
        for (int j = i + 1; j < 501; j++)
            g[i][j] = gcd(i, j);

    while (solve(g));
}