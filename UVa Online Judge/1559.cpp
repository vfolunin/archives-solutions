#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int stoneCount, int player, vector<int> &limit, vector<vector<int>> &memo) {
    int &res = memo[player][stoneCount];
    if (res != -1)
        return res;

    if (stoneCount == 1)
        return res = 0;

    for (int i = 1; i <= limit[player] && i < stoneCount; i++)
        if (!rec(stoneCount - i, (player + 1) % limit.size(), limit, memo))
            return res = 1;

    return res = 0;
}

bool solve() {
    int playerCount, stoneCount;
    if (!(cin >> playerCount >> stoneCount))
        return 0;

    playerCount *= 2;
    vector<int> limit(playerCount);
    for (int &x : limit)
        cin >> x;

    vector<vector<int>> memo(playerCount, vector<int>(stoneCount + 1, -1));
    cout << rec(stoneCount, 0, limit, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}