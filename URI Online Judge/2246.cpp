#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
    queue<int> q;
    q.push(y);
    q.push(x);
    visited[y][x] = 1;
    int size = 0;

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        size++;

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                a[ty][tx] == a[y][x] && !visited[ty][tx]) {
                q.push(ty);
                q.push(tx);
                visited[ty][tx] = 1;
            }
        }
    }

    return size;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    vector<vector<int>> visited(h, vector<int>(w));
    int res = 1e9;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (!visited[y][x])
                res = min(res, bfs(a, y, x, visited));

    cout << res << "\n";
}