#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<int> q;

    dist[0][0] = 0;
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + (a[y][x] - '0') * dy[d];
            int tx = x + (a[y][x] - '0') * dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist[h - 1][w - 1] != 1e9 ? dist[h - 1][w - 1] : -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    cout << bfs(a);
}