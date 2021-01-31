#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int h, int w) {
    static vector<vector<int>> memo(301, vector<int>(301, -1));
    if (memo[h][w] != -1)
        return memo[h][w];

    if (h == 1)
        return memo[h][w] = w - 1;
    if (w == 1)
        return memo[h][w] = h - 1;

    int res = 1e9;
    for (int i = 1; 2 * i <= h; i++)
        res = min(res, 1 + rec(i, w) + rec(h - i, w));
    for (int i = 1; 2 * i <= w; i++)
        res = min(res, 1 + rec(h, i) + rec(h, w - i));
    return memo[h][w] = res;
}

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    cout << rec(h, w) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}