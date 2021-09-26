#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int y1, int x1, int y2, int x2) {
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<int> q;

    dist[y1][x1] = 0;
    q.push(y1);
    q.push(x1);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
        int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < 8; d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < 8 && 0 <= tx && tx < 8 && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist[y2][x2];
}

void solve() {
    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << bfs(y1 - '1', x1 - 'a', y2 - '1', x2 - 'a') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}