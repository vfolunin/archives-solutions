#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a) {
    int h = a.size(), w = a[0].size();

    vector<vector<int>> visited(h, vector<int>(w));
    queue<int> q;

    visited[0][0] = 1;
    q.push(0);
    q.push(0);

    int borderSize = 0;

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ti = y + dy[d];
            int tj = x + dx[d];
            if (0 <= ti && ti < h && 0 <= tj && tj < w && a[ti][tj] == '0' && !visited[ti][tj]) {
                visited[ti][tj] = 1;
                q.push(ti);
                q.push(tj);
            }
            borderSize += 0 <= ti && ti < h && 0 <= tj && tj < w &&a[ti][tj] == '1';
        }
    }

    return borderSize;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h + 2, string(w + 2, '0'));
    for (int y = 1; y <= h; y++)
        for (int x = 1; x <= w; x++)
            cin >> a[y][x];

    cout << bfs(a);
}