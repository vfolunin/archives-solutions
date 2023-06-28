#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool bfs(int h, int w, int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> visited(h, vector<int>(w));
    queue<pair<int, int>> q;

    visited[startY][startX] = 1;
    q.push({ startY, startX });

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == finishY && x == finishX)
            return 1;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && !visited[ty][tx]) {
                visited[ty][tx] = 1;
                q.push({ ty, tx });
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, startY, startX, finishY, finishX;
    cin >> h >> w >> startY >> startX >> finishY >> finishX;

    cout << (bfs(h, w, startY - 1, startX - 1, finishY - 1, finishX - 1) ? "YES" : "NO");
}