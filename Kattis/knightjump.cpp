#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int sy, int sx) {
    int size = a.size();
    vector<vector<int>> dist(size, vector<int>(size, 1e9));
    queue<int> q;

    dist[sy][sx] = 0;
    q.push(sy);
    q.push(sx);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < 8; d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < size && 0 <= tx && tx < size && a[ty][tx] != '#' && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist[0][0] != 1e9 ? dist[0][0] : -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    int sy, sx;

    for (int y = 0; y < size; y++) {
        cin >> a[y];
        if (int x = a[y].find('K'); x != -1) {
            sy = y;
            sx = x;
        }
    }

    cout << bfs(a, sy, sx);
}