#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height, width;
    cin >> height >> width;

    if (!height && !width)
        return 0;

    vector<vector<int>> dist(height, vector<int>(width, -1));

    int bombRowCount;
    cin >> bombRowCount;

    for (int i = 0; i < bombRowCount; i++) {
        int y, bombColCount;
        cin >> y >> bombColCount;

        for (int j = 0; j < bombColCount; j++) {
            int x;
            cin >> x;
            dist[y][x] = 1e9;
        }
    }

    int startY, startX, finishY, finishX;
    cin >> startY >> startX >> finishY >> finishX;

    queue<int> q;
    q.push(startY);
    q.push(startX);
    dist[startY][startX] = 0;

    int dy[] = { -1, 0, 1, 0 };
    int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < height && 0 <= tx && tx < width && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    cout << dist[finishY][finishX] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}