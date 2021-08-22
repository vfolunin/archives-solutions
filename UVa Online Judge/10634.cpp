#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> prepare() {
    vector<vector<long long>> c(2001, vector<long long>(2001));
    for (int n = 0; n < c.size(); n++) {
        c[n][0] = 1;
        for (int k = 1; k <= n; k++)
            c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
    }

    vector<vector<long long>> res(1001, vector<long long>(1001));

    for (int n = 0; n < res.size(); n++)
        for (int v = 1; v < res.size(); v++)
            res[n][v] = c[n + v - 1][v - 1];
    
    for (int n = 2; n < res.size(); n++)
        for (int v = 1; v < res.size(); v++)
            res[n][v] += res[n - 2][v];

    return res;
}

bool solve() {
    int n, v;
    cin >> n >> v;

    if (!n && !v)
        return 0;

    static vector<vector<long long>> res = prepare();

    cout << res[n][v] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}