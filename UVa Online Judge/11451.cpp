#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<pair<int, int>> &sprinklers, int i, int last, int limit, int width, vector<vector<vector<int>>> &memo) {
    int &res = memo[i][last][limit];
    if (res != -1)
        return res;

    if (i == sprinklers.size())
        return res = 0;

    res = rec(sprinklers, i + 1, last, limit, width, memo);

    auto &[pos, maxRad] = sprinklers[i];
    for (int rad = 1; rad <= maxRad && rad <= limit; rad++) {
        int l = max(last + 1, pos - rad), r = min(width, pos + rad);
        int watered = l <= r ? r - l + 1 : 0;
        res = max(res, watered + rec(sprinklers, i + 1, max(last, r), limit - rad, width, memo));
    }

    return res;
}

void solve() {
    int width, sprinklerCount;
    cin >> width >> sprinklerCount;

    vector<pair<int, int>> sprinklers(sprinklerCount);
    for (auto &[pos, maxRad] : sprinklers)
        cin >> pos;

    int limit;
    cin >> limit;

    for (auto &[pos, maxRad] : sprinklers)
        cin >> maxRad;

    vector<vector<vector<int>>> memo(sprinklerCount + 1, vector<vector<int>>(width + 1, vector<int>(limit + 1, -1)));
    int res = rec(sprinklers, 0, 0, limit, width, memo);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}