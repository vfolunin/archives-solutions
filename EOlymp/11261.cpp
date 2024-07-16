#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    int width;
    cin >> width;

    if (!width)
        return 0;

    int n;
    cin >> n;

    vector<int> p(n);
    for (int &x : p)
        cin >> x;
    p.push_back(width);

    vector<vector<int>> d(p.size(), vector<int>(p.size()));
    for (int l = 0, r = 1; r < p.size(); l++, r++)
        d[l][r] = sum(p, l, r);
    for (int len = 3; len <= p.size(); len++) {
        for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
            d[l][r] = 1e9;
            for (int m = l; m < r; m++)
                d[l][r] = min(d[l][r], d[l][m] + d[m + 1][r]);
            d[l][r] += sum(p, l, r);
        }
    }

    cout << "The minimum cutting is " << d[0][n] << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}