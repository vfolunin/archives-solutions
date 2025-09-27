#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    queue<int> q;
    q.push(y);
    q.push(x);
    visited[y][x] = 1;

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                a[ty][tx] != 'X' && !visited[ty][tx]) {
                q.push(ty);
                q.push(tx);
                visited[ty][tx] = 1;
            }
        }
    }
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> visited(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == 'T')
                bfs(a, y, x, visited);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (visited[y][x] ? 'T' : a[y][x]);
        cout << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}