#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int c, int k5, int k10, int bottles, int money, vector<vector<vector<int>>> &memo) {
    int &res = memo[c][k5][k10];
    if (res != -1)
        return res;

    if (c == bottles)
        return res = 0;

    int k1 = money - c * 8 - k5 * 5 - k10 * 10;

    res = 1e9;
    if (k1 >= 8)
        res = min(res, 8 + rec(c + 1, k5, k10, bottles, money, memo));
    if (k5 >= 2)
        res = min(res, 2 + rec(c + 1, k5 - 2, k10, bottles, money, memo));
    if (k5 >= 1 && k1 >= 3)
        res = min(res, 4 + rec(c + 1, k5 - 1, k10, bottles, money, memo));
    if (k10 >= 1)
        res = min(res, 1 + rec(c + 1, k5, k10 - 1, bottles, money, memo));
    if (k10 >= 1 && k1 >= 3)
        res = min(res, 4 + rec(c + 1, k5 + 1, k10 - 1, bottles, money, memo));
    return res;
}

void solve() {
    int bottles, k1, k5, k10;
    cin >> bottles >> k1 >> k5 >> k10;

    int money = k1 + k5 * 5 + k10 * 10;
    vector<vector<vector<int>>> res(151, vector<vector<int>>(201, vector<int>(51, -1)));

    cout << rec(0, k5, k10, bottles, money, res) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}