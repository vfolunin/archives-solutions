#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aPointCount;
    cin >> aPointCount;

    if (!aPointCount)
        return 0;

    vector<vector<int>> dist(2001, vector<int>(2001, -1));
    queue<int> q;

    for (int i = 0; i < aPointCount; i++) {
        int y, x;
        cin >> y >> x;
        q.push(y);
        q.push(x);
        dist[y][x] = 0;
    }

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty <= 2000 && 0 <= tx && tx <= 2000 && dist[ty][tx] == -1) {
                q.push(ty);
                q.push(tx);
                dist[ty][tx] = dist[y][x] + 1;
            }
        }
    }

    int bPointCount;
    cin >> bPointCount;

    int res = 1e9;
    for (int i = 0; i < bPointCount; i++) {
        int y, x;
        cin >> y >> x;
        res = min(res, dist[y][x]);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}