#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int boxes, int l, int r) {
    static vector<vector<vector<int>>> memo(20, vector<vector<int>>(200, vector<int>(200, -1)));
    if (memo[boxes][l][r] != -1)
        return memo[boxes][l][r];

    if (boxes == 1)
        return memo[boxes][l][r] = (l + r) * (r - l + 1) / 2;
    if (l > r)
        return memo[boxes][l][r] = 0;

    int &res = memo[boxes][l][r];
    res = 1e9;
    for (int m = l; m <= r; m++)
        res = min(res, m + max(rec(boxes - 1, l, m - 1), rec(boxes, m + 1, r)));
    return res;
}

void solve() {
    int boxes, crackers;
    cin >> boxes >> crackers;
    cout << rec(boxes, 1, crackers) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}