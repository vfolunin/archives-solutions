#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (!a && !b)
        return 0;
    double p = (double)a / (a + b);

    vector<vector<double>> res(c + 1, vector<double>(2));
    res[0][0] = 1;   

    for (int i = 1; i <= c; i++) {
        res[i][0] = res[i - 1][1] * p + res[i - 1][0] * (1 - p);
        res[i][1] = res[i - 1][0] * p + res[i - 1][1] * (1 - p);
    }

    cout.precision(7);
    cout << fixed << res[c][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}