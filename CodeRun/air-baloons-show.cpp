#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &a, int y, int x, vector<vector<pair<int, int>>> &memo) {
    auto &res = memo[y][x];
    if (res.first != -1)
        return res;
    res = { 1, 1 };

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[y][x] > a[ty][tx]) {
            auto [toLength, toCount] = dfs(a, ty, tx, memo);
            if (res.first < toLength + 1)
                res = { toLength + 1, toCount };
            else if (res.first == toLength + 1)
                res.second += toCount;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<pair<int, int>>> memo(size, vector<pair<int, int>>(size, { -1, -1 }));
    pair<int, int> res;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (!y || y == size - 1 || !x || x == size - 1) {
                auto [length, count] = dfs(a, y, x, memo);
                if (res.first < length)
                    res = { length, count };
                else if (res.first == length)
                    res.second += count;
            }
        }
    }

    cout << res.first << " " << res.second;
}